#include "myglwindow.h"
#include "math/Vector2D.h"

using Math::Vector2D;
#define endl Qt::endl

static Vector2D verts[] ={
    Vector2D(+0.0f, +0.1f),
    Vector2D(-0.1f, -0.1f),
    Vector2D(+0.1f, -0.1f),
};

static const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);

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

    glGenBuffers(1, &vertexBufferId);
    glBindBuffer( GL_ARRAY_BUFFER, vertexBufferId );

    glBufferData( GL_ARRAY_BUFFER, sizeof(verts), NULL, GL_DYNAMIC_DRAW );
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0 );

    connect( &myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
    myTimer.start(0);


    Vector2D shipPosition( 0.5f, 0.5f );
    Vector2D translatedVerts[NUM_VERTS];

    for(unsigned int i = 0 ; i < NUM_VERTS ; i++ ){
        translatedVerts[i] = verts[i] + shipPosition;
    }
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);

    qDebug() << "end of initGL" << endl;
}

void MyGLWindow::updateForOSX(){

    frame++;
    if(frame % 1 == 0){
        if( this->size() == QSize(800, 600))
        {
            qDebug() << "this->size() == QSize(800, 600)" << endl;
            this->resize(QSize( 799.9, 599.9));
        }
        else
        {
            qDebug() << "else" << endl;
            this->resize(800, 600);
        }
    }

}

void MyGLWindow::myUpdate()
{
    qDebug() << __func__ << endl;
    updateForOSX();



}

void MyGLWindow::paintGL()
{
    qDebug() << __func__ << endl;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3 );

    update();

}

