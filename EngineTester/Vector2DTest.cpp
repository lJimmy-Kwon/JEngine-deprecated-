#include <QtTest>
#include "Vector2D.h"

using Math::Vector2D;

class Vector2DTest : public QObject
{
    Q_OBJECT

public:
    Vector2DTest(){};
    ~Vector2DTest(){};

private slots:
    void Constructor();
    void VectorAddition();
    void ScalarMultiplication();

};

void Vector2DTest::Constructor()
{
    Vector2D first( 1, 2 );
    QCOMPARE( first.x, 1 );
    QCOMPARE( first.y, 2 );
}

void Vector2DTest::VectorAddition()
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

void Vector2DTest::ScalarMultiplication()
{
    Vector2D vec( -7, 3 );
    Vector2D result1 = 8 * vec;
    Vector2D result2 = vec * 8;

    QCOMPARE(result1.x,-56 );
    QCOMPARE(result1.y, 24 );

    QCOMPARE(result1.x, result2.x );
    QCOMPARE(result1.y, result2.y );

}


QTEST_APPLESS_MAIN(Vector2DTest)

#include "Vector2DTest.moc"
