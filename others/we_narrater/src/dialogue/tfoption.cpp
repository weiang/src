#include "dialogue/tfoption.hpp"
#include "dialogue/optionloader.hpp"

using namespace _trb;
using namespace boost;
using namespace std;

const std::wstring TFOption::TFType    = L"TF";
const std::wstring TFOption::TAnswer   = L"T";
const std::wstring TFOption::FAnswer   = L"F";

//////////////////////////////////////////////////////////////////////////
TFOption::TFOption(const std::wstring& question) :
Option(question)
{
}

bool TFOption::getAnswers(
                          const std::wstring &sentence, 
                          std::vector<AnswerPtr> &answers_) const
{
    answers_.clear();

    bool T = true;
    for (AnswerVec::const_iterator iter = mAnswers.begin();
        iter != mAnswers.end() && T;
        ++iter)
    {
        if (sentence.find(iter->first) != string::npos)
        {
            if (iter->second->name() == FAnswer)
            {
                T = false;
                answers_.clear();
            }
            if (iter->second->name() == TAnswer ||
                iter->second->name() == FAnswer)
            {
                answers_.push_back(iter->second);
            }
        }
    }

    return !answers_.empty();
}
