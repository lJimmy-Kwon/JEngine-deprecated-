#include "common_test.h"


void common_test::roundFloatTest()
{
    float test1 = 1234.1234123412341234;
    float test2 = -1234.1234123412341234;
    float test3 = 1234.12;
    float test4 = 0.5;

    float result1 = roundFloat(test1, 4);
    float result2 = roundFloat(test2, 8);
    float result3 = roundFloat(test3, 8);
    float result4 = roundFloat(test4, 8);

    QCOMPARE(result1, 1234.1234f);
    QCOMPARE(result2, -1234.12341234f);
    QCOMPARE(result3, 1234.12f);
    QCOMPARE(result4, 0.5f);

    QCOMPARE(1.0f/2.0f, 0.5f);
}

void common_test::QFCOMPARETest()
{
    QFCOMPARE(0.1234128, 0.1234124f);
    QFCOMPARE(0.12341234, 0.12341234123513241f);

    QFCOMPARE(0.12348234, 0.12348214f);
    QFCOMPARE(-0.12348234, -0.12348132f);

    QFCOMPARE(-0.12, -0.12f);
}
