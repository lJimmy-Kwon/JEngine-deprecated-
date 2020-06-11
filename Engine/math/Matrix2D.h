#ifndef MATRIX2D_H
#define MATRIX2D_H

#include "Vector2D.h"
#include <QtMath>

namespace Math
{

    struct Matrix2D
    {
        float r0c0;
        float r0c1;
        float r1c0;
        float r1c1;

        inline explicit Matrix2D( float r0c0 = 1, float r0c1 = 0,
                  float r1c0 = 0, float r1c1 = 1 );

        inline static Matrix2D rotate(float angleInRadians);

    };

    inline Vector2D operator*(const Matrix2D& matrix, const Vector2D& vector );

    #include "Matrix2D.inl"


    Matrix2D::Matrix2D( float r0c0, float r0c1,
                        float r1c0, float r1c1 ) :
                        r0c0(r0c0), r0c1(r0c1),
                        r1c0(r1c0), r1c1(r1c1){}

    Vector2D operator*(const Matrix2D& matrix, const Vector2D& vector ){
        return Vector2D(
                    matrix.r0c0 * vector.x + matrix.r0c1 * vector.y,
                    matrix.r1c0 * vector.x + matrix.r1c1 * vector.y
                    );
    };

    Matrix2D Matrix2D::rotate(float angleInRadians){

        float cosResult = qCos(angleInRadians);
        float sinResult = qSin(angleInRadians);

        return Matrix2D(
                    cosResult, -sinResult,
                    sinResult, cosResult
                    );
    }

}


#endif // MATRIX2D_H
