#include "dialogue/prompter.hpp"

using namespace _trb;
using namespace boost;
using namespace std;

//////////////////////////////////////////////////////////////////////////
void Prompter::init()
{
    for (unsigned int i = 0; i < mInitOptions.size(); ++i)
    {
        mCandidates.push_back(mInitOptions[i]);
    }
}

OptionPtr Prompter::prompt()
{
    if (mCandidates.empty())
        mCurOption.reset();
    else
    {
        mCurOption = mCandidates.front();
        mCandidates.pop_front();
    }
    return mCurOption;
}

void Prompter::acknowledge(const AnswerPtr& answer)
{
    const OptionVec& vec = answer->options();
    for (OptionVec::const_reverse_iterator iter = vec.rbegin();
        iter != vec.rend();
        ++iter)
    {
        mCandidates.push_front(*iter);
    }
}
