#ifndef COMMON_TEST_H
#define COMMON_TEST_H

#include <QtTest>
#include <QDebug>
#include <QTest>

#include <math/Common.h>

class common_test : public QObject
{
    Q_OBJECT
public:
    common_test(){};
    ~common_test(){};

private slots:
    void roundFloatTest();
    void QFCOMPARETest();

};


#endif // COMMON_TEST_H
