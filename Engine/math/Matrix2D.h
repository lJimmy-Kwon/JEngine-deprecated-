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
        Vector2D temp;

        temp.x = matrix.r0c0 * vector.x + matrix.r0c1 * vector.y;
        temp.y = matrix.r1c0 * vector.x + matrix.r1c1 * vector.y;

        return temp;
    };

    Matrix2D Matrix2D::rotate(float angleInRadians){

        return Matrix2D(
                    qCos(angleInRadians), -qSin(angleInRadians),
                    qSin(angleInRadians), qCos(angleInRadians)
                    );
    }

}


#endif // MATRIX2D_H
