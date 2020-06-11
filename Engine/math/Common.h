#ifndef COMMON_H
#define COMMON_H
#include <QtCore>
#include <QtTest>

#define QFCOMPARE(x,y) QCOMPARE(roundFloat(x,6),roundFloat(y,6))

inline float roundFloat(float number, int point){

    return QString::number(number, 'f', point).toFloat();

}

#endif // COMMON_H
