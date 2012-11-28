#include "dialogue/dm.hpp"
#include "dialogue/optionloader.hpp"
#include "dialogue/synthesizer.hpp"
#include <sstream>

using namespace _trb;
using namespace std;
using namespace boost;

//////////////////////////////////////////////////////////////////////////
DialogManager::DialogManager(ros::Publisher& pub) :
StateMachine(S_greet),
mLoader(new OptionLoader),
mPrompter(new Prompter),
mSynthesizer(new Synthesizer(pub)),
mSpeechMutex(),
mSpeech(),
mSpeechResult(),
mCheckOpt(),
mCheckResult(),
mTopics(),
mStateDec(new const char*[S_total])
{
    mStateDec[S_fini] = "S_fini";
    mStateDec[S_greet] = "S_greet";
    mStateDec[S_intro] = "S_intro";
    mStateDec[S_question] = "S_question";
    mStateDec[S_answer] = "S_answer";
    mStateDec[S_check] = "S_check";
    mStateDec[S_acknowledge] = "S_acknowledge";
    mStateDec[S_repeat] = "S_repeat";
    mStateDec[S_requestion] = "S_requestion";

    OptionLoader::Pair tanswer(TFOption::TAnswer);
    tanswer.keywords.push_back(L"好");
    tanswer.keywords.push_back(L"是");
    tanswer.keywords.push_back(L"对");
 
    OptionLoader::Pair fanswer(TFOption::FAnswer);
    fanswer.keywords.push_back(L"不");

    OptionLoader::PairVec pairs;
    pairs.push_back(tanswer);
    pairs.push_back(fanswer);

    mCheckOpt = mLoader->create(TFOption::TFType, L"", pairs);

    mSpeechMutex.lock();
}

DialogManager::~DialogManager()
{
    mSpeechMutex.unlock();
}

void DialogManager::loadQuestions(const std::string &file_path)
{
    mLoader->load(file_path, mPrompter);
}

void DialogManager::input(const std::wstring& speech)
{
    mutex::scoped_try_lock lock(mSpeechMutex);
    if (lock)
    {
        mSpeech = speech;
    }
    else
    {
        wcout << "Failed to input speech" << endl;
    }
}

unsigned int DialogManager::transform(unsigned int state)
{
    if (state == S_greet && !firstCycle() && mSynthesizer->isFinished()) 
        return S_intro;
    else if (state == S_intro && getCurrStateCycle() > 300  && mSynthesizer->isFinished()) 
        return S_question;
    else if (state == S_question)
    {
        if (mPrompter->isEmpty() && !mPrompter->cur_option()) return S_fini;
        if (!firstCycle() && mSynthesizer->isFinished()) return S_answer;
    }
    else if (state == S_question && !firstCycle() && mSynthesizer->isFinished()) 
        return S_answer;
    else if (state == S_answer && mSpeechResult.isParsed)
    {
        if (mSpeechResult.isUnderstood)
        {
            if (boost::shared_dynamic_cast<TFOption>(mPrompter->cur_option()))
                return S_acknowledge;
            else
                return S_check;
        }
        else return S_repeat;
    }
    else if (state == S_check && mCheckResult.isParsed)
    {
        if (!mCheckResult.isUnderstood ||
            mCheckResult.answers[0]->name() == TFOption::FAnswer)
            return S_requestion;
        else return S_acknowledge;
    }
    else if (state == S_acknowledge && !firstCycle() && mSynthesizer->isFinished()) 
        return S_question;
    else if (state == S_repeat && !firstCycle() && mSynthesizer->isFinished()) 
        return S_answer;
    else if (state == S_requestion && !firstCycle() && mSynthesizer->isFinished()) 
        return S_answer;

    return state;
}

void DialogManager::execute(unsigned int state)
{
    if (state == S_greet && firstCycle())
    {
        mSynthesizer->synthesize(L"您好。");
    }
    else if (state == S_intro && firstCycle())
    {
        mSynthesizer->synthesize(L"我是由、中国科学技术大学团队、开发的导览机器人。下面我会问您一些问题，以便给您提供个性化的解说服务。");
    }
    else if (state == S_question && firstCycle())
    {
        mSynthesizer->synthesize(mPrompter->cur_option()->question());
    }
    else if (state == S_answer)
    {
        mutex::scoped_lock lock(mSpeechMutex);
        if (!mSpeech.empty() && !mSpeechResult.isParsed)
        {
            mSpeechResult.isUnderstood = mPrompter->cur_option()->getAnswers(
                mSpeech, mSpeechResult.answers);
            mSpeechResult.isParsed = true;
        }
    }
    else if (state == S_check)
    {
        if (firstCycle())
        {
            wostringstream oss;
            oss << L"您的答案是、" << mSpeechResult.answers[0]->name();
            unsigned int i = 1;
            while (i < mSpeechResult.answers.size() - 1)
            {
                oss << L"、" << mSpeechResult.answers[i]->name();
                ++i;
            }
            if (mSpeechResult.answers.size() >= 2)
            {
                oss << L"、和、" << mSpeechResult.answers[i]->name();
            }
            oss << L"吗？";

            mSynthesizer->synthesize(oss.str());
        }
        else 
        {
            mutex::scoped_lock lock(mSpeechMutex);
            if (!mSpeech.empty() && !mCheckResult.isParsed)
            {
                mCheckResult.isUnderstood = 
                    mCheckOpt->getAnswers(mSpeech, mCheckResult.answers);
                mCheckResult.isParsed = true;
            }
        }
    }
    else if (state == S_acknowledge && firstCycle())
    {
        mSynthesizer->synthesize(L"好的。");
        acknowledge();
    }
    else if (state == S_repeat && firstCycle())
    {
        mSynthesizer->synthesize(L"我不太明白您的意思，可以再说一遍吗？");
    }
    else if (state == S_requestion && firstCycle())
    {
        mSynthesizer->synthesize(mPrompter->cur_option()->question());
    }
}

void DialogManager::onTransformation(unsigned int old_state, unsigned int new_state)
{
    wcout << "State: " << mStateDec[new_state] << endl;

    if (old_state == S_answer ||
        old_state == S_check)
    {
        mSpeechMutex.lock();
    }

    if (new_state == S_question)
    {
        if (old_state == S_intro) mPrompter->init();
        mPrompter->prompt();
    }
    else if (new_state == S_answer)
    {
        mSpeech.clear();
        mSpeechResult.clear();
        mSpeechMutex.unlock();
    }
    else if (new_state == S_check)
    {
        mSpeech.clear();
        mCheckResult.clear();
        mSpeechMutex.unlock();
    }
}

void DialogManager::acknowledge()
{
    typedef Answer::TopicVec TopicVec;

    wcout << "ACK:";
    for (AnswerVec::const_iterator iter = mSpeechResult.answers.begin();
        iter != mSpeechResult.answers.end();
        ++iter)
    {
        AnswerPtr answer = *iter;
        mPrompter->acknowledge(answer);
        for (TopicVec::const_iterator topic = answer->topics().begin();
            topic != answer->topics().end();
            ++topic)
        {
            mTopics.insert(*topic);
        }

        wcout << " " << answer->name();
    }
    wcout << endl;
}
