#include "dialogue/dm.hpp"
#include "dialogue/narrater.hpp"
#include "dialogue/synthesizer.hpp"
#include "utility/salt/locale.hpp"
#include "ros/ros.h"
#include "we_narrater/Feedback.h"
#include "std_msgs/String.h"
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <iostream>

using namespace _trb;
using namespace boost;
using namespace std;

static ros::Publisher tts_pub;
static ros::Publisher prv_pub;
static boost::shared_ptr<DialogManager> dm;
static boost::shared_ptr<Narrater> narrater(new Narrater);
static string questions_path;
static string topics_path;
static boost::mutex dialog_mutex;
static boost::thread* dialog_thread = NULL;

void input()
{
    string sentence;
    while (getline(cin, sentence))
    {
        if (dm) dm->input(_salt::string2wstring(sentence));
    }
}

void spr_input(const std_msgs::String::ConstPtr& sentence)
{
    wcout << "recv spr: " << _salt::string2wstring(sentence->data) << endl;
    if (dm) dm->input(_salt::string2wstring(sentence->data.c_str()));
}

void tts_feedback(const std_msgs::String::ConstPtr& signal)
{
    if (signal->data == "ttsover" && dm)
    {
        dm->synthesizer()->finish();
    }
}

void dialog(const std::string& saved_path)
{
    mutex::scoped_lock lock(dialog_mutex);

    dm.reset(new DialogManager(tts_pub));
    dm->loadQuestions(questions_path);
    while (!dm->isFinished())
    {
        dm->run();
        this_thread::sleep(boost::posix_time::milliseconds(20));
    }

    for (DialogManager::TopicSet::const_iterator iter = dm->topics().begin();
        iter != dm->topics().end(); ++iter)
    {
        wcout << "Result: " << *iter << endl;
    }

    narrater->narrate(saved_path, dm->topics());

    dm.reset();
    std_msgs::String msg;
    msg.data = "finished";
    prv_pub.publish(msg);
    wcout << "Dialgue is finished!" << endl;
}

bool dialogue_serv(
    we_narrater::Feedback::Request& request, 
    we_narrater::Feedback::Response& response)
{
    mutex::scoped_try_lock lock(dialog_mutex);
    if (!lock) return false;

    dialog_thread = new thread(boost::bind(dialog, request.path));
    return true;
}

int main(int argc, char** argv)
{
    wcout.imbue(locale("zh_CN.utf-8"));
    ros::init(argc, argv, "we_narrater");
    ros::NodeHandle prv_hndl("~");
    ros::NodeHandle pub_hndl;

    prv_hndl.param("questions_path", questions_path, string("res/questions.xml"));
    prv_hndl.param("topics_path", topics_path, string("res/topics.xml"));

    narrater->importNarration(topics_path);
    
    //ros::Subscriber spr_sub = pub_hndl.subscribe("xfspeech/recostr", 100, spr_input);
    ros::Subscriber spr_sub = pub_hndl.subscribe("sprforbrain", 100, spr_input);
    ros::Subscriber tts_sub = pub_hndl.subscribe("xftts/pub", 100, tts_feedback);
    //ros::Subscriber tts_sub = pub_hndl.subscribe("tts/msg", 100, tts_feedback);
    tts_pub = pub_hndl.advertise<std_msgs::String>("xftts/sub", 100);
    //tts_pub = pub_hndl.advertise<std_msgs::String>("tts", 100);
    ros::ServiceServer narr_serv = prv_hndl.advertiseService("beginDialog", dialogue_serv);
    prv_pub = prv_hndl.advertise<std_msgs::String>("endDialog", 100);

    thread input_thread(input);

    ros::spin();

    input_thread.detach();
    if (dialog_thread) dialog_thread->detach();
    return 0;
}
