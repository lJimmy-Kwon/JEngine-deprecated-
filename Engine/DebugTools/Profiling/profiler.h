#ifndef PROFILER_H
#define PROFILER_H
#include <Misc/typeDefs.h>

#include <QObject>
#include <fstream>
#include <QDebug>
#include <QCoreApplication>
namespace Profiling {

    class Profiler : public QObject
    {
    public:
        static const uint MAX_FRAME_NUMBER = 1000;
        static const uint MAX_PROFILE_CATEGORIES = 20;
        static Profiler& getInstance();

    private:
        Profiler(){};
        Profiler(const Profiler&);
        Profiler& operator=(const Profiler&);
        static Profiler theInstance;
    public:

    #if PROFILEING_ON
        Q_OBJECT

        const char* fileName;

        uint frameIndex;
        uint categoryIndex;
        uint numUsedCategories;
        struct ProfileCategory{

            const char* name;
            float samples[MAX_FRAME_NUMBER];

        }categories[ MAX_PROFILE_CATEGORIES ];

        char getDelimiter( uint index) const;
        bool wrapped() const;
        void writeFrame(uint frameNumber) const;
        void writeData() const;
        bool currentFrameComplete() const;
    #endif
    #if PROFILEING_ON
    public:
        void initialize( const char* fileName );
        void newFrame();
        void shutdown();
        void addEntry( const char* category, float time );
    #else
        void initialize( const char* fileName ){};
        void newFrame(){};
        void shutdown(){};
        void addEntry( const char* category, float time ){};
    #endif
    };


}


#define profiler Profiling::Profiler::getInstance()
#define Profiler Profiler

#endif // PROFILER_H
