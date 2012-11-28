#ifndef __trb_optionloader_HPP__
#define __trb_optionloader_HPP__

#include <boost/shared_ptr.hpp>
#include "prompter.hpp"
#include "utility/tinyxml/tinyxml.h"
#include <vector>
#include <string>

namespace _trb
{
    class OptionLoader
    {
    protected:
        static const char* L_Questions;
        static const char* L_Option;
        static const char* A_Type;
        static const char* L_Question;
        static const char* L_Answer;
        static const char* A_Name;
        static const char* L_Keyword;
        static const char* L_Topic;

        typedef std::vector<std::wstring> StringVec;

    public:
        struct Pair
        {
            std::wstring answer;
            std::vector<std::wstring> keywords;

            Pair(const std::wstring& _answer) : answer(_answer), keywords() {}
        };

        typedef std::vector<Pair> PairVec;

    public:
        bool load(
            const std::string& file_path,
            boost::shared_ptr<Prompter> prompter);

        OptionPtr create(
            const std::wstring& type,
            const std::wstring& question, 
            const PairVec& pairs);

    protected:
        void load(TiXmlElement* questions, boost::shared_ptr<Prompter> prompter);

        OptionPtr buildOption(TiXmlElement* option);

        AnswerPtr buildAnswer(TiXmlElement* answer, StringVec& keywords_);
    };//OptionLoader
}//_trb

#endif//__trb_optionloader_HPP__
