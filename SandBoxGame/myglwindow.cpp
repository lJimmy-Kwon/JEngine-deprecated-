#include "myglwindow.h"
#include "ui_myglwindow.h"

static float verts[] ={
    +0.0f, +0.1f,
    -0.1f, -0.1f,
    +0.1f, -0.1f,
};

MyGLWindow::MyGLWindow()
{
    qDebug() << __func__ << Qt::endl;
}

MyGLWindow::~MyGLWindow()
{
    qDebug() << __func__ << Qt::endl;
}

void MyGLWindow::initializeGL()
{
    initializeOpenGLFunctions();

    glGenBuffers(1, &vertexBufferId);
    glBindBuffer( GL_ARRAY_BUFFER, vertexBufferId );


    glBufferData( GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW );
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0 );

    connect( &myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
    myTimer.start(0);

    qDebug() << "end of initGL" << Qt::endl;
}

void MyGLWindow::updateForOSX(){

    this->setWidth(799);
    this->setHeight(599);

}

void MyGLWindow::myUpdate()
{
    qDebug() << __func__ << Qt::endl;
}

void MyGLWindow::paintGL()
{
    qDebug() << __func__ << Qt::endl;

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3 );

    updateForOSX();
}

