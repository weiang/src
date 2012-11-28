#ifndef __trb_topic_HPP__
#define __trb_topic_HPP__

#include <boost/shared_ptr.hpp>
#include <list>
#include <string>
#include "content.hpp"

namespace _trb
{
    class Topic;
    typedef boost::shared_ptr<Topic> TopicPtr;

    class Topic
    {
    public:
        typedef std::list<TopicPtr> TopicList;
        typedef std::list<ContentPtr> ContentList;

    public:
        inline const TopicList& subtopics() const { return mSubtopics; }

        inline const ContentList& contents() const { return mContents; }

        inline const std::wstring& name() const { return mName; }

        inline const bool& isNecc() const { return mIsNecc; }

    protected:
        explicit Topic(const std::wstring& name);

    private:
        bool mIsNecc;

        std::wstring mName;

        TopicList mSubtopics;

        ContentList mContents;

        friend class Importer;
    };//Topic
}//_trb

#endif//__trb_topic_HPP__
