#include "profile_test.h"

#include <fstream>
using std::ifstream;
using std::string;

namespace
{

    char* categories[] = {
        "Category1",
        "Category2",
        "Category3"
    };

    const char* const PROFILE_FILE_NAME = "profiles.csv";
    const unsigned int NUM_CATEGORIES = sizeof(categories) / sizeof(*categories);
    const unsigned int NUM_FRAMES = 5;
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

void writeSamples(){
    Profiler profiler;

    profiler.initialize(PROFILE_FILE_NAME);



    float sampleNumber = 0;
    for( float frame = 0 ; frame < NUM_FRAMES ; frame++ ){

        profiler.newFrame();

        for( unsigned int cat = 0; cat < NUM_CATEGORIES; cat++){
            profiler.addEntry(categories[cat], sampleNumber++ );
        }
    }

    profiler.shutdown();


}

void profile_test::profiling()
{


    ifstream input( PROFILE_FILE_NAME );
    input.unsetf(std::ios_base::skipws);

    QCOMPARE(getNextToken(input), "Category1");
    QCOMPARE(getNextToken(input), "Category2");
    QCOMPARE(getNextToken(input), "Category3");

    for(int i = 0; i < ( NUM_FRAMES * NUM_CATEGORIES ); i++ ){

        string buf = getNextToken( input );
        QCOMPARE(atoi(buf.c_str()), i);

    }
}

void profile_test::excludeIncompleteFrames()
{

}
