#include "dialogue/topic.hpp"
#include "dialogue/content.hpp"

using namespace _trb;
using namespace boost;
using namespace std;

//////////////////////////////////////////////////////////////////////////
Topic::Topic(const std::wstring& name) :
mIsNecc(false),
mName(name),
mSubtopics(),
mContents()
{
}
