#include "matrix2d_test.h"

void matrix2D_test::Constructor()
{
    Matrix2D identity;
    QCOMPARE(identity.r0c0, 1.0f);
    QCOMPARE(identity.r0c1, 0.0f);
    QCOMPARE(identity.r1c0, 0.0f);
    QCOMPARE(identity.r1c1, 1.0f);
}

void matrix2D_test::MatrixVectorMultiply()
{
    Matrix2D op( 2, -3,
                 4, -5 );
    Vector2D victim( 3, 9 );

    Vector2D victimPrime = op * victim;

    QCOMPARE(victimPrime.x, -21.0f );
    QCOMPARE(victimPrime.y, -33.0f );
}
