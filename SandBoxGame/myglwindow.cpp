#include "myglwindow.h"
#include "math/Vector2D.h"
#include "math/Matrix2D.h"
#include "math/Vector3D.h"
#include "math/Matrix3D.h"

#define endl Qt::endl

using Math::Vector2D;
using Math::Matrix2D;
using Math::Vector3D;
using Math::Matrix3D;

using Timing::Clock;

namespace{

    Vector3D verts[] = {

        Vector3D(+0.0f, +sqrt(0.02f), 1),
        Vector3D(-0.1f, -0.1f, 1),
        Vector3D(+0.1f, -0.1f, 1),

    };

    Vector3D shipPosition;
    Vector3D shipVelocity;

    float shipOrientation = 0.0f;
    static const unsigned int NUM_VERTS = sizeof( verts ) / sizeof( *verts );

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

    glGenBuffers( 1, &vertexBufferId);
    glBindBuffer( GL_ARRAY_BUFFER, vertexBufferId );

    glBufferData( GL_ARRAY_BUFFER, sizeof( verts ), NULL, GL_DYNAMIC_DRAW );
    glEnableVertexAttribArray( 0 );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0 );

    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof( verts ), verts );

    connect( &myTimer, SIGNAL( timeout() ), this, SLOT( myUpdate() ));
    myTimer.start( 10 );

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
    rotateShip();
    updateVelocity();

    shipPosition += shipVelocity * frameClock.timeElapsedLastFrame();
}

void MyGLWindow::paintGL()
{

    int minSize = qMin( width(), height() );
    Vector2D viewportLocation;

    viewportLocation.x = width()  / 2.0f - minSize / 2.0f;
    viewportLocation.y = height() / 2.0f - minSize / 2.0f;

    glViewport( viewportLocation.x, viewportLocation.y, minSize, minSize );

    glClear( GL_COLOR_BUFFER_BIT );
    Vector3D transFormedVerts[ NUM_VERTS ];
    Matrix3D translator = Matrix3D::translate( shipPosition );
    Matrix3D rotator = Matrix3D::rotateZ( shipOrientation );
    Matrix3D op =  translator * rotator;

    for(unsigned int i = 0 ; i < NUM_VERTS ; i++ ){
        transFormedVerts[i] = op * verts[i];
    }

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(transFormedVerts), transFormedVerts);
    glDrawArrays(GL_TRIANGLES, 0, 3 );
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(transFormedVerts), transFormedVerts);
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

void MyGLWindow::updateVelocity(){

    Input::update();
    const float ACCELERATION = 0.0000002f * frameClock.timeElapsedLastFrame();

    Vector3D directionToAccelerate( -sin(shipOrientation), cos(shipOrientation));

    if( Input::keyPressed( Qt::Key_Up )){

        shipVelocity += directionToAccelerate * ACCELERATION;

    }
}

void MyGLWindow::rotateShip(){

    Input::update();
    const float ANGULAR_MOVEMENT = 0.02f;

    if( Input::keyPressed(Qt::Key_Right)){

        shipOrientation -= ANGULAR_MOVEMENT;

    }

    if( Input::keyPressed(Qt::Key_Left)){

        shipOrientation += ANGULAR_MOVEMENT;

    }

    if( Input::keyPressed(Qt::Key_Escape)){

        QApplication::quit();

    }
}

void MyGLWindow::keyPressEvent(QKeyEvent *event)
{

  if(event->isAutoRepeat())
  {
    event->ignore();
  }
  else
  {

    Input::registerKeyPress( event->key() );

  }

}

void MyGLWindow::keyReleaseEvent(QKeyEvent *event)
{

  if(event->isAutoRepeat())
  {

    event->ignore();

  }
  else
  {

    Input::registerKeyRelease(event->key());

  }

}

void MyGLWindow::mousePressEvent(QMouseEvent *event)
{

  Input::registerMousePress(event->button());

}

void MyGLWindow::mouseReleaseEvent(QMouseEvent *event)
{

  Input::registerMouseRelease(event->button());

}
