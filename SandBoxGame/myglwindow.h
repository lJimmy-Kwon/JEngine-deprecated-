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


private slots:
    void myUpdate();

private:

    GLuint vertexBufferId;
    QTimer myTimer;



    int frame = 0;
};


#endif // MYGLWINDOW_H
