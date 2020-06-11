#ifndef VECTOR3D_TEST_H
#define VECTOR3D_TEST_H

#include <QtTest>
#include "math/Vector3D.h"

using Math::Vector3D;

class vector3d_test : public QObject
{
    Q_OBJECT

public:
    vector3d_test(){};
    ~vector3d_test(){};

private slots:
    void Constructor();
    void AssignmentPlusEquals();
    void AssignmentMinusEquals();
    void VectorAddition();
    void ScalarMultiplication();

};



#endif // VECTOR3D_TEST_H
