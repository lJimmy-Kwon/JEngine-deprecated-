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

    QCOMPARE( victimPrime.x, -21.0f );
    QCOMPARE( victimPrime.y, -33.0f );
}

void matrix2D_test::Rotation()
{
    Matrix2D op = Matrix2D::rotate(0);
    QFCOMPARE(op.r0c0, 1.0f);
    QFCOMPARE(op.r0c1, 0.0f);
    QFCOMPARE(op.r1c0, 0.0f);
    QFCOMPARE(op.r1c1, 1.0f);

    op = Matrix2D::rotate(M_PI);
    QFCOMPARE(op.r0c0, -1.0f);
    QFCOMPARE(op.r0c1, 0.0f);
    QFCOMPARE(op.r1c0, 0.0f);
    QFCOMPARE(op.r1c1, -1.0f);

    op = Matrix2D::rotate(M_PI_2);
    QFCOMPARE(op.r0c0,  0.0f);
    QFCOMPARE(op.r0c1, -1.0f);
    QFCOMPARE(op.r1c0,  1.0f);
    QFCOMPARE(op.r1c1,  0.0f);

    op = Matrix2D::rotate(M_PI_4);
    QFCOMPARE(op.r0c0,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r0c1, -qSqrt(2) / 2.0f);
    QFCOMPARE(op.r1c0,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r1c1,  qSqrt(2) / 2.0f);

    op = Matrix2D::rotate(-M_PI_4);
    QFCOMPARE(op.r0c0,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r0c1,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r1c0, -qSqrt(2) / 2.0f);
    QFCOMPARE(op.r1c1,  qSqrt(2) / 2.0f);

    op = Matrix2D::rotate(M_PI / 3.0f);
    QFCOMPARE(op.r0c0, 0.5f);
    QFCOMPARE(op.r0c1,-qSqrt(3) / 2.0f);
    QFCOMPARE(op.r1c0, qSqrt(3) / 2.0f);
    QFCOMPARE(op.r1c1, 0.5f);

    op = Matrix2D::rotate(-M_PI / 3.0f);
    QFCOMPARE(op.r0c0, 0.5f);
    QFCOMPARE(op.r0c1, qSqrt(3) / 2.0f);
    QFCOMPARE(op.r1c0,-qSqrt(3) / 2.0f);
    QFCOMPARE(op.r1c1, 0.5f);

}
