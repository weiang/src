#ifndef __trb_content_HPP__
#define __trb_content_HPP__

#include <boost/shared_ptr.hpp>
#include <string>
#include <set>

namespace _trb
{
    class Content
    {
    protected:
        typedef std::set<unsigned int> PIDSet;

    public:
        inline const std::wstring& text() const { return mText; }

        inline const std::string& pos() const { return mPos; }

        inline const std::string& arm() const { return mArm; }

    protected:
        Content(
            const std::wstring& text,
            const std::string& pos,
            const std::string& arm) :
        mText(text), mPos(pos), mArm(arm) {}

    private:
        std::wstring mText;

        std::string mPos;

        std::string mArm;

        friend class Importer;
    };//Content

    typedef boost::shared_ptr<Content> ContentPtr;
}//_trb

#endif//__trb_content_HPP__
