#ifndef CLOCK_TEST_H
#define CLOCK_TEST_H

#include <QtTest>


class Clock_test : public QObject
{
    Q_OBJECT
public:
    Clock_test(){};
    ~Clock_test(){};

private slots:
    void Initialize();

};

#endif // CLOCK_TEST_H
