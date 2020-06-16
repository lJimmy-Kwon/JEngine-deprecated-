#include "profile_test.h"
#include <fstream>
using std::ifstream;
using std::string;

using Profiling::Profiler;

namespace
{
    char* categories[] = {
        "Category1",
        "Category2",
        "Category3"
    };

    const char* const PROFILE_FILE_NAME = "profiles.csv";
    const unsigned int NUM_CATEGORIES = sizeof(categories) / sizeof(*categories);
}


string getNextToken(ifstream& theFile){

    char c;
    string ret;

    while(theFile.good()){
        theFile >> c;
        if( c == ',' || c == '\n' )
            break;

        ret += c;
    }

    return ret;
}

void writeFrames(unsigned int numFrames){

    float sampleNumber = 0;
    for( float frame = 0 ; frame < numFrames ; frame++ ){

        profiler.newFrame();

        for( unsigned int cat = 0; cat < NUM_CATEGORIES; cat++){
            profiler.addEntry(categories[cat], sampleNumber++ );
        }
    }
}

bool isAtEndOfFile(ifstream& input){

    if(!input.good())
        return false;
    char bitBucket;
    input >> bitBucket;
    return !input.good();
}

void checkFrames(unsigned int numFrames, bool excludeLastFrame = false ){

    ifstream input( PROFILE_FILE_NAME );
    input.unsetf(std::ios_base::skipws);

    for(unsigned int i = 0; i < NUM_CATEGORIES; i++)
            QCOMPARE(getNextToken(input), categories[i]);

    unsigned int profileNumber = 0;

    if(numFrames >= Profiler::MAX_FRAME_NUMBER){

        profileNumber = (numFrames - Profiler::MAX_FRAME_NUMBER) * NUM_CATEGORIES;
        numFrames = Profiler::MAX_FRAME_NUMBER;
    }

    if(excludeLastFrame){
        profileNumber += NUM_CATEGORIES;
        numFrames--;
    }

    for(unsigned int i = 0; i < ( numFrames * NUM_CATEGORIES ); i++ ){

        string buf = getNextToken( input );
        QCOMPARE(atoi(buf.c_str()), profileNumber++);

    }

    QCOMPARE( isAtEndOfFile(input), true );

}

void profile_test::profiling()
{

    profiler.initialize(PROFILE_FILE_NAME);
    writeFrames(5);
    profiler.shutdown();
    checkFrames(5);

}

void profile_test::ExcludeIncompleteFrames()
{

}

void runTestsOnFrames(unsigned int numFrames){

    profiler.initialize(PROFILE_FILE_NAME);
    writeFrames(numFrames);
    profiler.shutdown();
    checkFrames(numFrames);

}

void profile_test::SamllAmountOfFrames()
{
    runTestsOnFrames( 5 );
}

void profile_test::LargeAmountOfFramesNonCircular()
{

    const unsigned int NUM_FRAMES_THIS_TEST =
            static_cast<unsigned int>( Profiler::MAX_FRAME_NUMBER * .8 );

    runTestsOnFrames( NUM_FRAMES_THIS_TEST );

}

void profile_test::ArrayBoundaries()
{

    runTestsOnFrames(Profiler::MAX_FRAME_NUMBER);
    runTestsOnFrames(Profiler::MAX_FRAME_NUMBER + 1 );
    runTestsOnFrames(Profiler::MAX_FRAME_NUMBER + 2 );

}

void profile_test::CirculatingOnePlusSome()
{
    runTestsOnFrames(Profiler::MAX_FRAME_NUMBER + 3  );
}

void profile_test::GoAroundSeveralTimes()
{
    runTestsOnFrames(Profiler::MAX_FRAME_NUMBER * 3.1415 );
}
