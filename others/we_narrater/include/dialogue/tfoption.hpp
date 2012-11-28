#ifndef __trb_tfoption_HPP__
#define __trb_tfoption_HPP__

#include "option.hpp"
#include <string>

namespace _trb
{
    class TFOption : public Option
    {
    public:
        static const std::wstring TFType;
        static const std::wstring TAnswer;
        static const std::wstring FAnswer;

    public:
        explicit TFOption(const std::wstring& question);

        bool getAnswers(
            const std::wstring& sentence, 
            std::vector<AnswerPtr>& answers_) const;
    };//TFOption
}//_trb

#endif//__trb_tfoption_HPP__
