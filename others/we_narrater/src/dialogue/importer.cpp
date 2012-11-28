#include "dialogue/importer.hpp"
#include "utility/salt/locale.hpp"
#include <iostream>

using namespace _trb;
using namespace _salt;
using namespace boost;
using namespace std;

const char* Importer::L_Type            = "type";
const char* Importer::L_Narration       = "narration";
const char* Importer::L_Topic           = "topic";
const char* Importer::A_Name            = "name";
const char* Importer::L_Content         = "content";
const char* Importer::A_Pos             = "pos";
const char* Importer::A_Arm             = "arm";
const char* Importer::A_Necc            = "necc";

//////////////////////////////////////////////////////////////////////////
Importer::Importer() :
mPosStack(),
mArmStack()
{
    mPosStack.push_back("[0,0,0]");
    mArmStack.push_back("[0,0,0]");
}

bool Importer::import(const std::string& file_path, std::list<TopicPtr>& topics_)
{
    TiXmlDocument doc(file_path);
    if (!doc.LoadFile())
    {
        cout << "Cannot load '" << file_path 
            << "'\n\tMessage='" << doc.ErrorDesc() << "'"<< endl;
        return false;
    }

    TiXmlElement* narration = doc.FirstChildElement(L_Narration);
    if (narration == NULL)
    {
        cout << "Cannot find the XML element '" << L_Narration << "'\n";
        return false;
    }

    import(narration, topics_);

    return true;
}

void Importer::import(TiXmlElement* narration, std::list<TopicPtr>& topics_)
{
    for (TiXmlElement* topic = narration->FirstChildElement(L_Topic);
        topic; topic = topic->NextSiblingElement(L_Topic))
    {
        TopicPtr ptr = buildTopic(topic);
        if (ptr) topics_.push_back(ptr);
    }
}

TopicPtr Importer::buildTopic(TiXmlElement* topic)
{
    const char* name = topic->Attribute(A_Name);
    if (name)
    {
        const char* pos = topic->Attribute(A_Pos);
        if (pos) mPosStack.push_back(string(pos));
        else mPosStack.push_back(mPosStack.back());

        const char* arm = topic->Attribute(A_Arm);
        if (arm) mArmStack.push_back(string(arm));
        else mArmStack.push_back(mArmStack.back());

        TopicPtr ptr(new Topic(string2wstring(name)));

        const char* necc = topic->Attribute(A_Necc);
        if (necc && string(necc) == "T") ptr->mIsNecc = true;

        for (TiXmlElement* content = topic->FirstChildElement(L_Content);
            content; content = content->NextSiblingElement(L_Content))
        {
            ContentPtr con_ptr = buildContent(content);
            if (con_ptr)
            {
                ptr->mContents.push_back(con_ptr);
            }
        }

        for (TiXmlElement* sub_topic = topic->FirstChildElement(L_Topic);
            sub_topic; sub_topic = sub_topic->NextSiblingElement(L_Topic))
        {
            TopicPtr st_ptr = buildTopic(sub_topic);
            if (st_ptr)
            {
                ptr->mSubtopics.push_back(st_ptr);
            }
        }

        mPosStack.pop_back();
        mArmStack.pop_back();

        return ptr;
    }
    else
    {
        cout << "Topic without a name is in [" 
            << topic->Row() << "," << topic->Column() << "]\n";
    }

    return TopicPtr();
}

ContentPtr Importer::buildContent(TiXmlElement* content)
{
    const char* text = content->GetText();
    if (text)
    {
        const char* pos_att = content->Attribute(A_Pos);
        string pos = (pos_att ? pos_att : mPosStack.back());

        const char* arm_att = content->Attribute(A_Arm);
        string arm = (arm_att ? arm_att : mArmStack.back());

        ContentPtr ptr(new Content(string2wstring(text), pos, arm));

        return ptr;
    }
    else
    {
        cout << "Content without the text is in ["
            << content->Row() << "," << content->Column() << "]\n";
    }

    return ContentPtr();
}
