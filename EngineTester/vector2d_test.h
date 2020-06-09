#ifndef VECTOR2D_TEST_H
#define VECTOR2D_TEST_H

#include <QtTest>
#include "math/Vector2D.h"

using Math::Vector2D;

class vector2D_test : public QObject
{
    Q_OBJECT

public:
    vector2D_test(){};
    ~vector2D_test(){};

private slots:
    void Constructor();
    void VectorAddition();
    void ScalarMultiplication();

};


#endif // VECTOR2D_TEST_H
