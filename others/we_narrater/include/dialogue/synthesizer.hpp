#ifndef __trb_synthesizer_HPP__
#define __trb_synthesizer_HPP__

#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include "ros/ros.h"

namespace _trb
{
    class Synthesizer
    {
    public:
        explicit Synthesizer(ros::Publisher& pub);

        void synthesize(const std::wstring& nl);

        bool isFinished() const;

        void finish();

    private:
        bool mIsFinished;

        mutable boost::mutex mMutex;

        ros::Publisher& mPublisher;
    };//Synthesizer

    typedef boost::shared_ptr<Synthesizer> SynthesizerPtr;
}//_trb

#endif//__trb_synthesizer_HPP__
