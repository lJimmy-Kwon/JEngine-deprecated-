#include "profiler.h"
#include <cassert>
#include <string>

static std::ofstream outStream;

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

    ProfileCategory& pc = categories[categoryIndex];

    if( frameIndex == 0 ){
        pc.name = category;
        numUsedCategories++;
    }
    else{

        assert( pc.name == category && category != NULL );
        assert( categoryIndex < numUsedCategories);

    }

    pc.samples[ frameIndex % MAX_FRAME_NUMBER ] = time;
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
    writeData();
}

bool Profiler::wrapped() const
{
    return frameIndex >= MAX_FRAME_NUMBER && frameIndex != -1;
}

void Profiler::writeFrame(unsigned int frameNumber) const
{
    for(unsigned int cat = 0; cat < numUsedCategories; cat++){
        outStream << categories[cat].samples[frameNumber];
        outStream << getDelimiter(cat);
    }
}

void Profiler::writeData() const
{
    outStream.open(fileName, std::ios::trunc );

    for(unsigned int i = 0; i < numUsedCategories; i++ ){

        outStream << categories[i].name;
        outStream << getDelimiter(i);

    }

    unsigned int endIndex;
    unsigned int startIndex;

    if(wrapped()){

        endIndex = frameIndex % MAX_FRAME_NUMBER;
        startIndex = (endIndex + 1) % MAX_FRAME_NUMBER;
        while (startIndex != endIndex) {
            writeFrame(startIndex);
            startIndex = (startIndex + 1 ) % MAX_FRAME_NUMBER;
        }
        if(currentFrameComplete())
            writeFrame(startIndex);

    }else{

        unsigned int numActualFrames = frameIndex;
        if(currentFrameComplete())
            numActualFrames++;

        startIndex = 0;
        endIndex = numActualFrames;

        while ( startIndex < endIndex){

            writeFrame(startIndex++);
        }

    }

    outStream.close();
}

char Profiler::getDelimiter( unsigned int index) const
{
   char delimiter = (( index + 1 ) < numUsedCategories) ? ',' : '\n';
   return delimiter;
}

bool Profiler::currentFrameComplete() const {
    return categoryIndex == numUsedCategories;
}
