#ifndef __trb_importer_HPP__
#define __trb_importer_HPP__

#include <string>
#include <list>
#include "topic.hpp"
#include "utility/tinyxml/tinyxml.h"

namespace _trb
{
    class Importer
    {
    protected:
        static const char* L_Type;
        static const char* L_Narration;
        static const char* L_Topic;
        static const char* A_Name;
        static const char* L_Content;
        static const char* A_Pos;
        static const char* A_Arm;
        static const char* A_Necc;

        typedef std::list<std::string> StringList;

    public:
        Importer();

        bool import(
            const std::string& file_path,
            std::list<TopicPtr>& topics_);

    protected:
        void import(TiXmlElement* narration, std::list<TopicPtr>& topics_);

        TopicPtr buildTopic(TiXmlElement* topic);

        ContentPtr buildContent(TiXmlElement* content);

    private:
        StringList mPosStack;
        StringList mArmStack;
    };//Importer
}//_trb

#endif//_trb_importer_HPP__
