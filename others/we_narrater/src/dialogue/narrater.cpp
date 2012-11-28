#include "dialogue/narrater.hpp"
#include "dialogue/importer.hpp"
#include "utility/salt/locale.hpp"
#include <iostream>

using namespace _trb;
using namespace std;
using namespace boost;

//////////////////////////////////////////////////////////////////////////
Narrater::Narrater() :
mImporter(new Importer),
mTopics(),
mSelectedTopics(),
mSavedFile()
{
}

bool Narrater::importNarration(const std::string& file_path)
{
    return mImporter->import(file_path, mTopics);
}

void Narrater::narrate(
    const std::string& save_path,
    const std::set<std::wstring>& selected)
{
    mSelectedTopics = selected;

    mSavedFile.open(save_path.c_str());
    mSavedFile.imbue(locale("zh_CN.utf-8"));
    mSavedFile << "#!/usr/bin/env python2\n# -*- coding:utf-8 -*-\n\n";
    mSavedFile << "poseandtext=[";
    for (TopicList::const_iterator iter = mTopics.begin();
        iter != mTopics.end();
        ++iter)
    {
        TopicPtr topic = *iter;
        for_each_topic(
            topic,
            (mSelectedTopics.find(topic->name()) != mSelectedTopics.end()));
    }
    mSavedFile << "]";
    mSavedFile.close();
}

void Narrater::for_each_topic(const TopicPtr& topic, bool selected)
{
    typedef Topic::ContentList ContentList;

    if (selected || 
        topic->isNecc() ||
        (mSelectedTopics.find(topic->name()) != mSelectedTopics.end()))
    {
        for (ContentList::const_iterator citer = topic->contents().begin();
            citer != topic->contents().end(); ++citer)
        {
            for_each_content(*citer);
        }
        for (TopicList::const_iterator titer = topic->subtopics().begin();
            titer != topic->subtopics().end(); ++titer)
        {
            for_each_topic(*titer, true);
        }
    }
    else
    {
        for (TopicList::const_iterator titer = topic->subtopics().begin();
            titer != topic->subtopics().end(); ++titer)
        {
            for_each_topic(*titer, false);
        }
    }
}

void Narrater::for_each_content(const ContentPtr& content)
{
    //wcout << "Tourobot: " << content->text() << "\n\t"
    //    << _salt::string2wstring(content->pos()) << " " 
    //    << _salt::string2wstring(content->arm()) << endl;
    mSavedFile << "[" << _salt::string2wstring(content->pos())
        << ",[\"" << content->text() 
        << "\"]," << _salt::string2wstring(content->arm()) << "],\n";
}
