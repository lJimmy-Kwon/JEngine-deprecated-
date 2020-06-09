#include "Clock.h"

namespace Timing {

    bool Clock::initialize()
    {
        timer.start();
        timeLastFrame = timer.elapsed();

        return true;
    }

    bool Clock::shutdown()
    {
        return true;
    }

    void Clock::newFrame()
    {
        deltaLastFrame = timer.elapsed() - timeLastFrame;
        timeLastFrame  = timer.elapsed();
    }

    float Clock::timeElapsedLastFrame() const
    {
        return deltaLastFrame;
    }

}

