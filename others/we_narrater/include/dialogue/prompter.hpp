#ifndef __trb_prompter_HPP__
#define __trb_prompter_HPP__

#include <boost/shared_ptr.hpp>
#include "option.hpp"
#include <vector>
#include <list>

namespace _trb
{
    class Prompter
    {
    protected:
        typedef std::vector<OptionPtr>  OptionVec;
        typedef std::list<OptionPtr>    OptionList;

    public:
        void init();

        OptionPtr prompt();

        void acknowledge(const AnswerPtr& answer);

        inline OptionPtr cur_option() const { return mCurOption; }

        inline bool isEmpty() const { return mCandidates.empty(); }

    private:
        OptionPtr mCurOption;

        OptionList mCandidates;

        OptionVec mInitOptions;

        friend class OptionLoader;
    };//Prompter
}//_trb

#endif//__trb_prompter_HPP__
