#include "dialogue/synthesizer.hpp"
#include "utility/salt/locale.hpp"
#include <iostream>
#include "std_msgs/String.h"

using namespace _trb;
using namespace std;

//////////////////////////////////////////////////////////////////////////
Synthesizer::Synthesizer(ros::Publisher& pub) :
mIsFinished(true),
mMutex(),
mPublisher(pub)
{
}

void Synthesizer::synthesize(const std::wstring& nl)
{
    setlocale(LC_ALL, "zh_CN.utf-8");

    boost::mutex::scoped_lock lock(mMutex);
    wcout << "Tourobot: " << nl << endl;
    mIsFinished = false;

    std_msgs::String msg;
    msg.data = _salt::wstring2string(nl);
    mPublisher.publish(msg);
}

bool Synthesizer::isFinished() const
{
    boost::mutex::scoped_lock lock(mMutex);
    return mIsFinished;
}

void Synthesizer::finish()
{
    boost::mutex::scoped_lock lock(mMutex);
    mIsFinished = true;
}
