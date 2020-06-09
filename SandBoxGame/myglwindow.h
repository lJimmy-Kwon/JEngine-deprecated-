#ifndef MYGLWINDOW_H
#define MYGLWINDOW_H

#include <QOpenGLFunctions>
#include <QOpenGLWindow>
#include <QWidget>

#include <QOpenGLContext>
#include <QDebug>
#include <QTimer>

#include "Timing/Clock.h"

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

private slots:
    void myUpdate();

private:

    GLuint vertexBufferId;
    QTimer myTimer;



    int frame = 0;
};


#endif // MYGLWINDOW_H
