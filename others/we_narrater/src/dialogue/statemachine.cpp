#include "dialogue/statemachine.hpp"

using namespace _trb;

//////////////////////////////////////////////////////////////////////////
StateMachine::StateMachine(
                           unsigned int init_state, 
                           unsigned int fini_state /* = 0 */, 
                           unsigned int max_cycle_per_state /* = 0 */) :
mLastState(fini_state),
mCurrState(init_state),
mFiniState(fini_state),
mTotalCycle(0),
mCurrStateCycle(0),
mMaxCyclePerState(max_cycle_per_state)
{
}

void StateMachine::run()
{
    if (mCurrState == mFiniState) return;

    update();

    mLastState = mCurrState;
    mCurrState = transform(mCurrState);
    if (mCurrState == mFiniState) return;

    if (mCurrState != mLastState)
    {
        mCurrStateCycle = 0;
        onTransformation(mLastState, mCurrState);

        while (true)
        {
            mLastState = mCurrState;
            mCurrState = transform(mCurrState);
            if (mCurrState == mLastState) break;

            onTransformation(mLastState, mCurrState);
            if (mCurrState == mFiniState) return;
        }
    }

    execute(mCurrState);

    ++mCurrStateCycle;
    if (mMaxCyclePerState > 0 &&
        mCurrStateCycle > mMaxCyclePerState)
    {
        mLastState = mCurrState;
        mCurrState = mFiniState;
    }

    ++mTotalCycle;
}
