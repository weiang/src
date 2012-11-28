#ifndef __trb_statemachine_HPP__
#define __trb_statemachine_HPP__

namespace _trb
{
    class StateMachine
    {
    public:
        StateMachine(
            unsigned int init_state,
            unsigned int fini_state = 0,
            unsigned int max_cycle_per_state = 0);

        virtual ~StateMachine() {}

        inline bool isFinished() const { return mCurrState == mFiniState; }

        inline unsigned int last_state() const { return mLastState; }
        inline unsigned int curr_state() const { return mCurrState; }

        inline unsigned int getCurrStateCycle() const { return mCurrStateCycle; }

        inline unsigned int getTotalCycle() const { return mTotalCycle; }

        void run();

    protected:
        virtual void update() {}

        virtual unsigned int transform(unsigned int state) = 0;

        virtual void execute(unsigned int state) = 0;

        virtual void onTransformation(
            unsigned int old_state, 
            unsigned int new_state) {}

    private:
        unsigned int mLastState;
        unsigned int mCurrState;
        unsigned int mFiniState;

        unsigned int mTotalCycle;
        unsigned int mCurrStateCycle;
        unsigned int mMaxCyclePerState;
    };//StateMachine
}//_trb

#endif//__trb_statemachine_HPP__
