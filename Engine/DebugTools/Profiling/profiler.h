#ifndef PROFILER_H
#define PROFILER_H

#include <QObject>
#include <fstream>

class Profiler : public QObject
{
    Q_OBJECT

    const char* fileName;

    static const unsigned int MAX_FRAME_SAMPLES = 500;
    static const unsigned int MAX_PROFILE_CATEGORIES = 20;
    unsigned int frameIndex;
    unsigned int categoryIndex;
    unsigned int numUsedCategories;

    struct ProfileCategory{

        const char* name;
        float samples[MAX_FRAME_SAMPLES];

    }categories[ MAX_PROFILE_CATEGORIES ];

    char getDelimiter( unsigned int index) const;

public:
    explicit Profiler( QObject *parent = nullptr );
    void initialize( const char* fileName );
    void addEntry( const char* category, float time );
    void newFrame();
    void shutdown();

signals:

};


#endif // PROFILER_H
