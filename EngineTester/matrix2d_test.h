#ifndef MATRIX2D_TEST_H
#define MATRIX2D_TEST_H

#include <QtTest>
#include <QtMath>
#include "math/Matrix2D.h"
#include "math/Vector2D.h"
#include "math/Common.h"

using Math::Matrix2D;
using Math::Vector2D;



class matrix2D_test : public QObject
{
    Q_OBJECT

public:
    explicit matrix2D_test(){};
    ~matrix2D_test(){};

private slots:
    void Constructor();
    void MatrixVectorMultiply();
    void Rotation();
//    void CopyConstructor();
//    void AssignmentOperators();
//    void AssignmentPlusEquals();
//    void AssignmentMinusEquals();
//    void VectorAddition();
//    void ScalarMultiplication();

};


#endif // MATRIX2D_TEST_H
