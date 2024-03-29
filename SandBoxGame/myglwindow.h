#ifndef MYGLWINDOW_H
#define MYGLWINDOW_H

#include <QOpenGLFunctions>
#include <QOpenGLWindow>
#include <QWidget>

#include <QOpenGLContext>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QApplication>

#include "Timing/Clock.h"
#include "input/input.h"
#include "DebugTools/Profiling/profile.h"
#include "DebugTools/Profiling/profiler.h"

#include <QTest>

class MyGLWindow : public QOpenGLWindow,
        protected QOpenGLFunctions
{
    Q_OBJECT
public:
    MyGLWindow();
    ~MyGLWindow();

    void initializeGL() override;
    void paintGL() override;

    void updateForOSX();
    bool initialize();
    bool shutdown();

protected:
    void updateVelocity();
    void rotateShip();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void checkBounderies();
    void lerpTheLerper();
    void targetNextLerpPoint();

    bool is_updated = false;


private slots:
    void myUpdate();

private:




    int frame = 0;
};


#endif // MYGLWINDOW_H
