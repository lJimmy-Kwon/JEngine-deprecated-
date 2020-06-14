#include "profiler.h"
#include <cassert>
#include <string>

Profiler::Profiler( QObject *parent ) : QObject( parent )
{

}

void Profiler::initialize( const char* fileName )
{

    this -> fileName = fileName;
    frameIndex    = -1;
    categoryIndex =  0;
    numUsedCategories = 0;

}

void Profiler::addEntry( const char *category, float time )
{
    assert( categoryIndex < MAX_PROFILE_CATEGORIES);
    assert( frameIndex < MAX_FRAME_SAMPLES );

    ProfileCategory& pc = categories[categoryIndex];

    if( frameIndex == 0 ){
        pc.name = category;
        numUsedCategories++;
    }
    else{

        assert( pc.name == category && category != NULL );
        assert( categoryIndex < numUsedCategories);

    }

    pc.samples[ frameIndex ] = time;
    categoryIndex++;

}

void Profiler::newFrame()
{
    if(frameIndex > 0 )
        assert( categoryIndex == numUsedCategories );

    frameIndex++;
    categoryIndex = 0;

}

void Profiler::shutdown()
{
    std::ofstream outStream(fileName, std::ios::trunc );

    for(unsigned int i = 0; i < numUsedCategories; i++ ){

        outStream << categories[i].name;
        outStream << getDelimiter(i);

    }

    unsigned int numActualFrames = frameIndex;
    if(categoryIndex == numUsedCategories)
        numActualFrames++;

    for( unsigned int frame = 0; frame < numActualFrames; frame++){
        for(unsigned int cat = 0; cat < numUsedCategories; cat++){
            outStream << categories[cat].samples[frame];
            outStream << getDelimiter(cat);
        }
    }

}

char Profiler::getDelimiter( unsigned int index) const
{
   char delimiter = (( index + 1 ) < numUsedCategories) ? ',' : '\n';
   return delimiter;
}
