#include "myglwindow.h"
#include "math/Vector2D.h"

#define endl Qt::endl

using Math::Vector2D;
using Timing::Clock;

namespace{

    Vector2D verts[] ={
        Vector2D(+0.0f, +0.1f),
        Vector2D(-0.1f, -0.1f),
        Vector2D(+0.1f, -0.1f),
    };

    Vector2D shipPosition;
    static const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);

    Clock frameClock;

}

MyGLWindow::MyGLWindow()
{
    qDebug() << __func__ << endl;
}

MyGLWindow::~MyGLWindow()
{
    qDebug() << __func__ << endl;
}

void MyGLWindow::initializeGL()
{
    initializeOpenGLFunctions();

    glViewport(0, 0, 800, 600 );

    glGenBuffers(1, &vertexBufferId);
    glBindBuffer( GL_ARRAY_BUFFER, vertexBufferId );

    glBufferData( GL_ARRAY_BUFFER, sizeof(verts), NULL, GL_DYNAMIC_DRAW );
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0 );

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);

    connect( &myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
    myTimer.start(10);

    qDebug() << "end of initGL" << endl;
}

void MyGLWindow::updateForOSX(){

    frame++;
    if(frame % 2 == 0){
        if( this->size() == QSize(800, 600))
        {
            this->resize(QSize( 799, 599));
        }
        else
        {
            this->resize(800, 600);
        }
    }

}

void MyGLWindow::myUpdate()
{
    updateForOSX();
    frameClock.newFrame();

}

void MyGLWindow::paintGL()
{
    qDebug() << __func__ << endl;

    glClear( GL_COLOR_BUFFER_BIT );

    Vector2D translatedVerts[NUM_VERTS];

    for(unsigned int i = 0 ; i < NUM_VERTS ; i++ ){
        translatedVerts[i] = verts[i] + shipPosition;
    }

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);
    glDrawArrays(GL_TRIANGLES, 0, 3 );
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);
    glDrawArrays(GL_TRIANGLES, 0, 3 );

}

bool MyGLWindow::initialize()
{
   return  frameClock.initialize();
}

bool MyGLWindow::shutdown()
{
    qDebug() << __func__ << endl;
    return frameClock.shutdown();
}

void MyGLWindow::keyPressEvent(QKeyEvent* e)
{
    const float SPEED = 0.02f;
    if( e->key() == Qt::Key_Up){
        shipPosition.y += SPEED;
    }

    if( e->key() == Qt::Key_Down){
        shipPosition.y -= SPEED;
    }

    if( e->key() == Qt::Key_Right){
        shipPosition.x += SPEED;
    }
    if( e->key() == Qt::Key_Left){
        shipPosition.x -= SPEED;
    }

    if( e->key() == Qt::Key_Escape){
        QApplication::quit();
    }
}
