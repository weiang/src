#include "dialogue/optionloader.hpp"
#include "dialogue/tfoption.hpp"
#include "utility/salt/locale.hpp"
#include <fstream>
#include <iostream>

using namespace _trb;
using namespace boost;
using namespace std;

const char* OptionLoader::L_Questions   = "questions";
const char* OptionLoader::L_Option      = "option";
const char* OptionLoader::A_Type        = "type";
const char* OptionLoader::L_Question    = "question";
const char* OptionLoader::L_Answer      = "answer";
const char* OptionLoader::A_Name        = "name";
const char* OptionLoader::L_Keyword     = "keyword";
const char* OptionLoader::L_Topic       = "topic";

//////////////////////////////////////////////////////////////////////////
bool OptionLoader::load(
                        const std::string &file_path, 
                        boost::shared_ptr<Prompter> prompter)
{
    TiXmlDocument doc(file_path);
    if (!doc.LoadFile())
    {
        cout << "Cannot load '" << file_path
            << "'\n\tMessage='" << doc.ErrorDesc() << "'" << endl;
        return false;
    }

    TiXmlElement* questions = doc.FirstChildElement(L_Questions);
    if (questions == NULL)
    {
        cout << "Cannot find the XML element '" << L_Questions << "'\n";
        return false;
    }

    load(questions, prompter);

    return true;
}

void OptionLoader::load(
                        TiXmlElement* questions, 
                        boost::shared_ptr<Prompter> prompter)
{
    for (TiXmlElement* option = questions->FirstChildElement(L_Option);
        option; option = option->NextSiblingElement(L_Option))
    {
        OptionPtr ptr = buildOption(option);
        if (ptr) prompter->mInitOptions.push_back(ptr);
    }
}

OptionPtr OptionLoader::buildOption(TiXmlElement* option)
{
    TiXmlElement* question = option->FirstChildElement(L_Question);
    const char* q_text = (question ? question->GetText() : NULL);
    if (question == NULL || q_text == NULL)
    {
        cout << "Option without the question in ["
            << option->Row() << "," << option->Column() << "]\n";
        return OptionPtr();
    }

    TiXmlElement* answer = option->FirstChildElement(L_Answer);
    if (answer == NULL)
    {
        cout << "Option without any answer in ["
            << option->Row() << "," << option->Column() << "]\n";
        return OptionPtr();
    }

    // TODO: According to the type of option, new a different Option
    OptionPtr option_ptr;
    const char* type = option->Attribute(A_Type);
    if (type && _salt::string2wstring(type) == TFOption::TFType)
        option_ptr.reset(new TFOption(_salt::string2wstring(q_text)));
    else
        option_ptr.reset(new Option(_salt::string2wstring(q_text)));

    StringVec keywords;
    while (answer)
    {
        AnswerPtr answer_ptr = buildAnswer(answer, keywords);
        if (answer_ptr)
        {
            for (unsigned int i = 0; i < keywords.size(); ++i)
            {
                option_ptr->mAnswers.push_back(make_pair(keywords[i], answer_ptr));
            }
        }

        keywords.clear();
        answer = answer->NextSiblingElement(L_Answer);
    }

    return option_ptr;
}

AnswerPtr OptionLoader::buildAnswer(
                                    TiXmlElement *answer, 
                                    StringVec &keywords_)
{
    const char* name = answer->Attribute(A_Name);
    if (name == NULL)
    {
        cout << "Answer without the name in ["
            << answer->Row() << "," << answer->Column() << "]\n";
        return AnswerPtr();
    }

    keywords_.clear();
    for (TiXmlElement* keyword = answer->FirstChildElement(L_Keyword);
        keyword; keyword = keyword->NextSiblingElement(L_Keyword))
    {
        const char* text = keyword->GetText();
        if (text)
        {
            keywords_.push_back(_salt::string2wstring(text));
        }
    }
    if (keywords_.empty())
    {
        cout << "Answer without the keyword(s) in ["
            << answer->Row() << "," << answer->Column() << "]\n";
        return AnswerPtr();
    }

    AnswerPtr answer_ptr(new Answer(_salt::string2wstring(name)));

    for (TiXmlElement* option = answer->FirstChildElement(L_Option);
        option; option = option->NextSiblingElement(L_Option))
    {
        OptionPtr option_ptr = buildOption(option);
        if (option_ptr) answer_ptr->mOptions.push_back(option_ptr);
    }

    for (TiXmlElement* topic = answer->FirstChildElement(L_Topic);
        topic; topic = topic->NextSiblingElement(L_Topic))
    {
        const char* text = topic->GetText();
        if (text) answer_ptr->mTopics.push_back(_salt::string2wstring(text));
    }

    return answer_ptr;
}

OptionPtr OptionLoader::create(
                               const std::wstring& type,
                               const std::wstring& question, 
                               const PairVec& pairs)
{
    OptionPtr option;
    if (type == TFOption::TFType)
        option.reset(new TFOption(question));
    else
        option.reset(new Option(question));

    for (PairVec::const_iterator piter = pairs.begin();
        piter != pairs.end(); ++piter)
    {
        AnswerPtr answer(new Answer(piter->answer));
        for (vector<wstring>::const_iterator witer = piter->keywords.begin();
            witer != piter->keywords.end(); ++witer)
        {
            option->mAnswers.push_back(make_pair(*witer, answer));
        }
    }

    return option;
}
