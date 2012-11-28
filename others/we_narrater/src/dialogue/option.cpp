#include "dialogue/option.hpp"
#include <iostream>

using namespace _trb;
using namespace std;

//////////////////////////////////////////////////////////////////////////
Option::Option(const std::wstring& question) :
mQuestion(question),
mAnswers()
{
}

bool Option::getAnswers(
                    const std::wstring& sentence, 
                    std::vector<AnswerPtr>& answers_) const
{
    answers_.clear();

    for (AnswerVec::const_iterator iter = mAnswers.begin();
        iter != mAnswers.end();
        ++iter)
    {
        if (sentence.find(iter->first) != wstring::npos)
        {
            answers_.push_back(iter->second);
        }
    }

    return !answers_.empty();
}
