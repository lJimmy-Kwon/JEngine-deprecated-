#include "clock_test.h"
#include "Timing/Clock.h"

using Timing::Clock;

void Clock_test::Initialize()
{

    Clock clock;
    QCOMPARE(clock.initialize(), true);
    QCOMPARE(clock.shutdown(), true);

}

void Clock_test::FrameTimeMeasuring()
{
    Clock clock;
    QCOMPARE(clock.initialize(), true);

    QTest::qSleep(1000);
    clock.lap();

    float timedTime = clock.lastlapTime();
    QCOMPARE( 900 < timedTime, true );
    QCOMPARE(timedTime < 1100, true );

    clock.lap();
    QTest::qSleep(500);
    clock.lap();

    timedTime = clock.lastlapTime();
    QCOMPARE( 400 < timedTime , true );
    QCOMPARE(timedTime < 600 , true );

    const int NUM_TESTS = rand() % 100;
    const float THRESHOLD = 10;

    for( int i = 0 ; i < NUM_TESTS; i++ ){
        int thisTestMiliseconds = rand() % 10000;
        float thisTestSeconds = thisTestMiliseconds;

        clock.lap();
        QTest::qSleep(thisTestMiliseconds);
        clock.lap();

        float elapsedSeconds = clock.lastlapTime();
        QCOMPARE( (thisTestSeconds - THRESHOLD) <  elapsedSeconds, true );
        QCOMPARE(  elapsedSeconds < (thisTestSeconds + THRESHOLD), true );

    }

    clock.lap();
    clock.lastlapTime();

    QCOMPARE(clock.shutdown(), true);
}
