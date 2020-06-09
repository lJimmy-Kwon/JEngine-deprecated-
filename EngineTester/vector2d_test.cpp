#include "vector2d_test.h"

void vector2D_test::Constructor()
{
    Vector2D first( 1, 2 );
    QCOMPARE( first.x, 1 );
    QCOMPARE( first.y, 2 );
}

void vector2D_test::VectorAddition()
{
    Vector2D first(1, 2);
    Vector2D second(3, 4);

    Vector2D result1  = first  + second;
    Vector2D result2 = second + first;

    QCOMPARE(result1.x, 4);
    QCOMPARE(result1.y, 6);

    QCOMPARE(first.x + second.x, result1.x);

    QCOMPARE(result1.x, result2.x);
    QCOMPARE(result1.y, result2.y);

}

void vector2D_test::ScalarMultiplication()
{
    Vector2D vec( -7, 3 );
    Vector2D result1 = 8 * vec;
    Vector2D result2 = vec * 8;

    QCOMPARE(result1.x,-56 );
    QCOMPARE(result1.y, 24 );

    QCOMPARE(result1.x, result2.x );
    QCOMPARE(result1.y, result2.y );

}
