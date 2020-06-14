#ifndef PROFILE_TEST_H
#define PROFILE_TEST_H

#include <QtTest>
#include "DebugTools/Profiling/profiler.h"

class profile_test : public QObject
{
    Q_OBJECT

public:
    profile_test(){};
    ~profile_test(){};

private slots:
    void profiling();
    void excludeIncompleteFrames();

};


#endif // PROFILE_TEST_H
