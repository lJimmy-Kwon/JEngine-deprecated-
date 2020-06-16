#ifndef PROFILE_H
#define PROFILE_H

#if PROFILEING_ON
#include "Timing/Clock.h"
#include "DebugTools/Profiling/profiler.h"
using Timing::Clock;
#endif



namespace Profiling {
    class Profile{
#if PROFILEING_ON
        const char* category;
        Clock clock;
#endif
#if PROFILEING_ON
        public:
            Profile(const char* category) : category(category)
            {

                clock.initialize();
                clock.start();

            }
            ~Profile(){

                clock.stop();
                profiler.addEntry( category, clock.lastlapTime());

            }
#else
    public:
        Profile(const char* category){};
        ~Profile(){};
#endif

    };
}

#define PROFILE(category) Profiling::Profile p(category)

#endif // PROFILE_H
