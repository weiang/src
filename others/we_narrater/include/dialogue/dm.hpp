#ifndef __trb_dm_HPP__
#define __trb_dm_HPP__

#include <string>
#include <vector>
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include "statemachine.hpp"
#include "option.hpp"
#include "tfoption.hpp"
#include "prompter.hpp"
#include "ros/ros.h"

namespace _trb
{
    class OptionLoader;
    class Synthesizer;

    class DialogManager : public StateMachine
    {
    protected:
        enum State
        {
            S_fini = 0,
            S_greet,
            S_intro,
            S_question,
            S_answer,
            S_check,
            S_acknowledge,
            S_repeat,
            S_requestion,
            S_total
        };

        typedef std::vector<AnswerPtr> AnswerVec;

        struct Result
        {
            bool isParsed;
            bool isUnderstood;
            AnswerVec answers;

            void clear()
            {
                isParsed = false;
                isUnderstood = false;
                answers.clear();
            }

            Result() : isParsed(false), isUnderstood(false), answers() {}
        };

    public:
        typedef std::set<std::wstring> TopicSet;

    public:
        explicit DialogManager(ros::Publisher& pub);
        ~DialogManager();

        void loadQuestions(const std::string& file_path);

        void input(const std::wstring& speech);

        const TopicSet& topics() const { return mTopics; }

        boost::shared_ptr<Synthesizer> synthesizer() const { return mSynthesizer; }

    protected:
        unsigned int transform(unsigned int state);

        void execute(unsigned int state);

        void onTransformation(unsigned int old_state, unsigned int new_state);

        inline bool firstCycle() const { return getCurrStateCycle() == 0; }

        void acknowledge();

    private:
        boost::shared_ptr<OptionLoader> mLoader;

        boost::shared_ptr<Prompter> mPrompter;

        boost::shared_ptr<Synthesizer> mSynthesizer;

        boost::mutex mSpeechMutex;

        std::wstring mSpeech;

        Result mSpeechResult;

        OptionPtr mCheckOpt;

        Result mCheckResult;

        TopicSet mTopics;

        const char** mStateDec;
    };//DialogManager
}//_trb

#endif//__trb_dm_HPP__
