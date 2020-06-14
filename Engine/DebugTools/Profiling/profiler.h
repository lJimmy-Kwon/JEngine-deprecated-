#ifndef PROFILER_H
#define PROFILER_H

#include <QObject>
#include <fstream>

class Profiler : public QObject
{
    Q_OBJECT

    const char* fileName;
    static const unsigned int MAX_PROFILE_CATEGORIES = 20;
    unsigned int frameIndex;
    unsigned int categoryIndex;
    unsigned int numUsedCategories;

public:
    static const unsigned int MAX_FRAME_NUMBER = 1000;

    struct ProfileCategory{

        const char* name;
        float samples[MAX_FRAME_NUMBER];

    }categories[ MAX_PROFILE_CATEGORIES ];

    char getDelimiter( unsigned int index) const;


    explicit Profiler( QObject *parent = nullptr );
    void initialize( const char* fileName );
    void addEntry( const char* category, float time );
    void newFrame();
    void shutdown();
    bool wrapped() const;

    void writeFrame(unsigned int frameNumber) const;
    void writeData() const;

    bool currentFrameComplete() const;

signals:

};


#endif // PROFILER_H
