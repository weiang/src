#ifndef __trb_narrater_HPP__
#define __trb_narrater_HPP__

#include <boost/shared_ptr.hpp>
#include <list>
#include <set>
#include <string>
#include <fstream>
#include "topic.hpp"

namespace _trb
{
    class Importer;

    class Narrater
    {
    protected:
        typedef std::list<TopicPtr> TopicList;

    public:
        Narrater();

        bool importNarration(const std::string& file_path);

        void narrate(
            const std::string& save_path,
            const std::set<std::wstring>& selected);

    protected:
        void for_each_topic(const TopicPtr& topic, bool selected);

        void for_each_content(const ContentPtr& content);

    private:
        boost::shared_ptr<Importer> mImporter;

        TopicList mTopics;

        std::set<std::wstring> mSelectedTopics;

        std::wofstream mSavedFile;
    };//Narrater
}//_trb

#endif//__trb_narrater_HPP__
