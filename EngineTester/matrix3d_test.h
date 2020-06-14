#ifndef MATRIX3D_H_test
#define MATRIX3D_H_test

#include <QtTest>
#include <QtMath>
#include "math/Vector3D.h"
#include "math/Matrix3D.h"
#include "math/Common.h"

using Math::Vector3D;
using Math::Matrix3D;


class matrix3D_test : public QObject
{
    Q_OBJECT

public:
    explicit matrix3D_test(){};
    ~matrix3D_test(){};

private slots:
    void Constructor();
    void MatrixVectorMultiply();
    void MatrixMatrixMultiply();
    void Rotation();
    void Translate();
};

#endif // MATRIX3D_H
