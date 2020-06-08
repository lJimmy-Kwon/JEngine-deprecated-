#ifndef MYGLWINDOW_H
#define MYGLWINDOW_H

#include <QOpenGLFunctions>
#include <QOpenGLWindow>
#include <QWidget>

#include <QOpenGLContext>
#include <QDebug>
#include <QTimer>

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

private slots:
    void myUpdate();

private:

    GLuint vertexBufferId;
    QTimer myTimer;
};


#endif // MYGLWINDOW_H
