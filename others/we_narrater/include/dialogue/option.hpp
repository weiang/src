#ifndef __trb_option_HPP__
#define __trb_option_HPP__

#include <string>
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>

namespace _trb
{
    class Answer;
    typedef boost::shared_ptr<Answer> AnswerPtr;

    class Option
    {
    protected:
        typedef std::pair<std::wstring, AnswerPtr> AnswerPair;
        typedef std::vector<AnswerPair> AnswerVec;

    public:
        explicit Option(const std::wstring& question);

        virtual ~Option() {}

        inline const std::wstring& question() const { return mQuestion; }

        virtual bool getAnswers(
            const std::wstring& sentence, 
            std::vector<AnswerPtr>& answers_) const;

    protected:
        std::wstring mQuestion;

        AnswerVec mAnswers;

        friend class OptionLoader;
    };//Option

    typedef boost::shared_ptr<Option> OptionPtr;

    class Answer
    {
    public:
        typedef std::vector<OptionPtr>      OptionVec;
        typedef std::vector<std::wstring>   TopicVec;

    public:
        explicit Answer(const std::wstring& name) :
        mName(name), mOptions(), mTopics() {}

        inline const std::wstring& name() const { return mName; }

        inline const OptionVec& options() const { return mOptions; }

        inline const TopicVec& topics() const { return mTopics; }

    private:
        std::wstring mName;

        OptionVec mOptions;

        TopicVec mTopics;

        friend class OptionLoader;
    };//Answer
}//_trb

#endif//__trb_option_HPP__
