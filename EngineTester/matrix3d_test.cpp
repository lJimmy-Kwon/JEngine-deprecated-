#include "matrix3d_test.h"
void matrix3D_test::Constructor()
{
    Matrix3D identity;

    QCOMPARE(identity.r0c0, 1.0f);
    QCOMPARE(identity.r0c1, 0.0f);
    QCOMPARE(identity.r0c2, 0.0f);

    QCOMPARE(identity.r1c0, 0.0f);
    QCOMPARE(identity.r1c1, 1.0f);
    QCOMPARE(identity.r1c2, 0.0f);

    QCOMPARE(identity.r2c0, 0.0f);
    QCOMPARE(identity.r2c1, 0.0f);
    QCOMPARE(identity.r2c2, 1.0f);

    Matrix3D victim( 1, 2, 3,
                     4, 5, 6,
                     7, 8, 9);

    QCOMPARE(victim.r0c0, 1.0f);
    QCOMPARE(victim.r0c1, 2.0f);
    QCOMPARE(victim.r0c2, 3.0f);

    QCOMPARE(victim.r1c0, 4.0f);
    QCOMPARE(victim.r1c1, 5.0f);
    QCOMPARE(victim.r1c2, 6.0f);

    QCOMPARE(victim.r2c0, 7.0f);
    QCOMPARE(victim.r2c1, 8.0f);
    QCOMPARE(victim.r2c2, 9.0f);

    Matrix3D identity2 = victim;

    QCOMPARE(identity2.r0c0, 1.0f);
    QCOMPARE(identity2.r0c1, 2.0f);
    QCOMPARE(identity2.r0c2, 3.0f);

    QCOMPARE(identity2.r1c0, 4.0f);
    QCOMPARE(identity2.r1c1, 5.0f);
    QCOMPARE(identity2.r1c2, 6.0f);

    QCOMPARE(identity2.r2c0, 7.0f);
    QCOMPARE(identity2.r2c1, 8.0f);
    QCOMPARE(identity2.r2c2, 9.0f);

}

void matrix3D_test::MatrixVectorMultiply()
{
    Matrix3D op( 1, 2, 3,
                 4, 5, 6,
                 7, 8, 9);

    Vector3D victim( 3, 9, 1 );
    Vector3D victimPrime = op * victim;

    QCOMPARE( victimPrime.x, 3 * 1 + 9 * 2 + 1 * 3 );
    QCOMPARE( victimPrime.y, 4 * 3 + 9 * 5 + 6 * 1 );
    QCOMPARE( victimPrime.z, 3 * 7 + 9 * 8 + 9 * 1 );
}

void matrix3D_test::Rotation()
{
    Matrix3D op = Matrix3D::rotateZ(0);

    QCOMPARE(op.r0c0, 1.0f);
    QCOMPARE(op.r0c1, 0.0f);
    QCOMPARE(op.r0c2, 0.0f);

    QCOMPARE(op.r1c0, 0.0f);
    QCOMPARE(op.r1c1, 1.0f);
    QCOMPARE(op.r1c2, 0.0f);

    QCOMPARE(op.r2c0, 0.0f);
    QCOMPARE(op.r2c1, 0.0f);
    QCOMPARE(op.r2c2, 1.0f);

    op = Matrix3D::rotateZ(M_PI);
    QFCOMPARE(op.r0c0, -1.0f);
    QFCOMPARE(op.r0c1, 0.0f);
    QFCOMPARE(op.r0c2, 0.0f);


    QFCOMPARE(op.r1c0, 0.0f);
    QFCOMPARE(op.r1c1, -1.0f);
    QFCOMPARE(op.r1c2, 0.0f);

    QFCOMPARE(op.r2c0, 0.0f);
    QFCOMPARE(op.r2c1, 0.0f);
    QFCOMPARE(op.r2c2, 1.0f);


    op = Matrix3D::rotateZ(M_PI_2);
    QFCOMPARE(op.r0c0,  0.0f);
    QFCOMPARE(op.r0c1, -1.0f);
    QFCOMPARE(op.r0c2,  0.0f);

    QFCOMPARE(op.r1c0,  1.0f);
    QFCOMPARE(op.r1c1,  0.0f);
    QFCOMPARE(op.r1c2,  0.0f);

    QFCOMPARE(op.r2c0, 0.0f);
    QFCOMPARE(op.r2c1, 0.0f);
    QFCOMPARE(op.r2c2, 1.0f);

    op = Matrix3D::rotateZ(M_PI_4);
    QFCOMPARE(op.r0c0,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r0c1, -qSqrt(2) / 2.0f);
    QFCOMPARE(op.r0c2,  0.0f);

    QFCOMPARE(op.r1c0,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r1c1,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r1c2,  0.0f);

    QFCOMPARE(op.r2c0, 0.0f);
    QFCOMPARE(op.r2c1, 0.0f);
    QFCOMPARE(op.r2c2, 1.0f);

    op = Matrix3D::rotateZ(-M_PI_4);
    QFCOMPARE(op.r0c0,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r0c1,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r0c2,  0.0f);

    QFCOMPARE(op.r1c0, -qSqrt(2) / 2.0f);
    QFCOMPARE(op.r1c1,  qSqrt(2) / 2.0f);
    QFCOMPARE(op.r1c2,  0.0f);

    QFCOMPARE(op.r2c0, 0.0f);
    QFCOMPARE(op.r2c1, 0.0f);
    QFCOMPARE(op.r2c2, 1.0f);


    op = Matrix3D::rotateZ(M_PI / 3.0f);
    QFCOMPARE(op.r0c0, 0.5f);
    QFCOMPARE(op.r0c1,-qSqrt(3) / 2.0f);
    QFCOMPARE(op.r0c2,  0.0f);

    QFCOMPARE(op.r1c0, qSqrt(3) / 2.0f);
    QFCOMPARE(op.r1c1, 0.5f);
    QFCOMPARE(op.r1c2,  0.0f);

    QFCOMPARE(op.r2c0, 0.0f);
    QFCOMPARE(op.r2c1, 0.0f);
    QFCOMPARE(op.r2c2, 1.0f);


    op = Matrix3D::rotateZ(-M_PI / 3.0f);
    QFCOMPARE(op.r0c0,  0.5f);
    QFCOMPARE(op.r0c1, qSqrt(3) / 2.0f);
    QFCOMPARE(op.r0c2,  0.0f);

    QFCOMPARE(op.r1c0,-qSqrt(3) / 2.0f);
    QFCOMPARE(op.r1c1,  0.5f);
    QFCOMPARE(op.r1c2,  0.0f);

    QFCOMPARE(op.r2c0, 0.0f);
    QFCOMPARE(op.r2c1, 0.0f);
    QFCOMPARE(op.r2c2, 1.0f);


}
