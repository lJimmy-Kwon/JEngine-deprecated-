#include "vector3d_test.h"

void vector3d_test::Constructor()
{
    Vector3D first( 1, 2, 3 );
    QCOMPARE( first.x, 1 );
    QCOMPARE( first.y, 2 );
    QCOMPARE( first.z, 3 );

}

void vector3d_test::VectorAddition()
{
    Vector3D first(1, 2, 3);
    Vector3D second(3, 4, 5);

    Vector3D result1  = first  + second;
    Vector3D result2  = second + first;

    QCOMPARE(result1.x, 4);
    QCOMPARE(result1.y, 6);
    QCOMPARE(result1.z, 8);

    QCOMPARE(first.x + second.x, result1.x);
    QCOMPARE(first.y + second.y, result1.y);
    QCOMPARE(first.z + second.z, result1.z);

    QCOMPARE(result1.x, result2.x);
    QCOMPARE(result1.y, result2.y);
    QCOMPARE(result1.z, result2.z);

}

void vector3d_test::ScalarMultiplication()
{
    Vector3D vec( -7, 3, 1 );
    Vector3D result1 = 8 * vec;
    Vector3D result2 = vec * 8;

    QCOMPARE(result1.x,-56 );
    QCOMPARE(result1.y, 24 );
    QCOMPARE(result1.z, 8 );

    QCOMPARE(result1.x, result2.x );
    QCOMPARE(result1.y, result2.y );
    QCOMPARE(result1.z, result2.z );

}

void vector3d_test::AssignmentPlusEquals(){

    Vector3D source( 5, -1234.5678f, 1.123123f);
    Vector3D another( 1, 1, 1.123124f);

    another += source;

    QCOMPARE(another.x, 6 );
    QCOMPARE(another.y, -1233.5678f );
    QCOMPARE(another.z, 1.123124f +  1.123123f);

}

void vector3d_test::AssignmentMinusEquals(){

    Vector3D source( 5, -1234.5678f, 1);
    Vector3D another( 1, 1, 2         );

    another -= source;

    QCOMPARE(another.x, -4 );
    QCOMPARE(another.y, 1235.5678f );
    QCOMPARE(another.z, 1          );

}
