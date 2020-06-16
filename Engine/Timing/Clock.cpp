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

    void Clock::start()
    {
        timer.restart();
        timeLastFrame = timer.elapsed();
    }

    void Clock::stop()
    {

        deltaLastFrame = timer.elapsed() - timeLastFrame;
        timeLastFrame  = timer.elapsed();

    }

    void Clock::lap()
    {
        stop();
        start();
    }

    float Clock::lastlapTime() const
    {
        return deltaLastFrame;
    }

}

