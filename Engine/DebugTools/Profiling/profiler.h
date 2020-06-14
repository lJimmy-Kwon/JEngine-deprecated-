#ifndef PROFILER_H
#define PROFILER_H

#include <QObject>
#include <fstream>

class Profiler : public QObject
{
public:
    static const unsigned int MAX_FRAME_NUMBER = 1000;
    static const unsigned int MAX_PROFILE_CATEGORIES = 20;
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

    unsigned int frameIndex;
    unsigned int categoryIndex;
    unsigned int numUsedCategories;
    struct ProfileCategory{

        const char* name;
        float samples[MAX_FRAME_NUMBER];

    }categories[ MAX_PROFILE_CATEGORIES ];

    char getDelimiter( unsigned int index) const;
    bool wrapped() const;
    void writeFrame(unsigned int frameNumber) const;
    void writeData() const;
    bool currentFrameComplete() const;
#endif
#if PROFILEING_ON
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

#define profiler Profiler::getInstance()

#endif // PROFILER_H
