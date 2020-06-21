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

    Vector3D shipVerts[] = {

        Vector3D(+0.0f, +sqrt(0.02f), 1.0f),
        Vector3D(-0.1f, -0.1f, 1.0f),
        Vector3D(+0.1f, -0.1f, 1.0f),

        Vector3D(+0.0f, +sqrt(0.02f), 1.0f),
        Vector3D(-0.1f, -0.1f, 1.0f),
        Vector3D(+0.1f, -0.1f, 1.0f),

        Vector3D( -0.0f, +1.0f, 1.0f ),
        Vector3D( -1.0f, +0.0f, 1.0f ),
        Vector3D( -0.0f, -1.0f, 1.0f ),
        Vector3D( +1.0f, +0.0f, 1.0f ),

    };

    GLushort indices[] = {0, 1, 1, 2, 2, 0, 0 + 3, 1 + 3, 1 + 3, 2 + 3, 2 + 3, 0 + 3, 3 + 3, 4 + 3, 4 + 3, 5 + 3, 5 + 3, 6 + 3, 6 + 3, 3 + 3};

    Vector3D bounderyVerts[] ={

        Vector3D( -0.0f, +1.0f, 0.0f ),
        Vector3D( -1.0f, +0.0f, 0.0f ),
        Vector3D( -0.0f, -1.0f, 0.0f ),
        Vector3D( +1.0f, +0.0f, 0.0f ),

    };

    Vector3D lerpPoints[] = {
        Vector3D(+0.5f, +0.5f, +0.0f ),
        Vector3D(-0.5f, +0.5f, +0.0f ),
        Vector3D(-0.5f, -0.5f, +0.0f ),
        Vector3D(+0.5f, -0.5f, +0.0f ),
    };

    const uint NUM_LERP_POINTS = sizeof(lerpPoints) / sizeof(*lerpPoints);
    uint sourceLerpPoint;
    uint destinationLerpPoint;
    float lerpAlpha;
    Vector3D currentLerperPosition;

    Vector3D shipPosition;
    Vector3D oldShipPosition;
    Vector3D shipVelocity;

    float shipOrientation = 0.0f;
    static const unsigned int NUM_shipVerts = sizeof( shipVerts ) / sizeof( *shipVerts );
    static const unsigned int NUM_BOUNDARY_VERTS = sizeof( bounderyVerts ) / sizeof( *bounderyVerts );

    GLuint shipVertexBufferId;
    GLuint boundaryVertsBufferID;
    GLuint indicesBufferId;

    QTimer myTimer;
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
    glEnableVertexAttribArray( 0 );

    if(NUM_LERP_POINTS > 1){

        lerpAlpha = 0.0f;
        destinationLerpPoint = 1;
        targetNextLerpPoint();

    }

    glViewport(0, 0, 800, 600 );

    glGenBuffers( 1, &shipVertexBufferId);
    glBindBuffer( GL_ARRAY_BUFFER, shipVertexBufferId );
    glBufferData( GL_ARRAY_BUFFER, sizeof(shipVerts), NULL, GL_DYNAMIC_DRAW );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0 );
    glPointSize(10.0f);

    glGenBuffers(1, &indicesBufferId );
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBufferId );
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
                 indices, GL_STATIC_DRAW );

    connect( &myTimer, SIGNAL( timeout() ), this, SLOT( myUpdate() ));
    myTimer.start( 10 );

    qDebug() << "end of initGL" << endl;

}

void MyGLWindow::updateForOSX(){

    frame++;

    if( frame % 2 == 0 ){

        if( this->size() == QSize( 800, 600 ))
        {
            this->resize( QSize( 799, 599 ) );
        }
        else
        {
            this->resize( 800, 600 );
        }
    }
}

void MyGLWindow::targetNextLerpPoint(){

    sourceLerpPoint = destinationLerpPoint;
    destinationLerpPoint = (destinationLerpPoint + 1) % NUM_LERP_POINTS;

}

void MyGLWindow::lerpTheLerper(){

    lerpAlpha += 0.0002f * frameClock.lastlapTime();
    
    if(  lerpAlpha >= 1.0f ){
         lerpAlpha = 0.0f;
         targetNextLerpPoint();
    }
    
    const Vector3D& source = lerpPoints[sourceLerpPoint];
    const Vector3D& destination = lerpPoints[destinationLerpPoint];

    currentLerperPosition = Math::lerp(lerpAlpha, source, destination );

}

void MyGLWindow::myUpdate()
{
    updateForOSX();
    frameClock.lap();
    rotateShip();
    updateVelocity();
    oldShipPosition = shipPosition;

    shipPosition += shipVelocity * frameClock.lastlapTime();
    checkBounderies();

    lerpTheLerper();

    is_updated = true;
}

void MyGLWindow::paintGL()
{
    if(is_updated){
        profiler.newFrame();

        int minSize = qMin( width(), height() );
        Vector2D viewportLocation;

        viewportLocation.x = width()  / 2.0f - minSize / 2.0f;
        viewportLocation.y = height() / 2.0f - minSize / 2.0f;

        glViewport( 0, 0, width(), height() );

        glClear( GL_COLOR_BUFFER_BIT );
        Vector3D transFormedshipVerts[ NUM_shipVerts ];
        Matrix3D translator = Matrix3D::translate( shipPosition );
        Matrix3D rotator = Matrix3D::rotateZ( shipOrientation );

        float aspectRatio = static_cast<float>(width() / height());
        Matrix3D scale = Matrix3D::scale( 1/ aspectRatio, 1 );


        Matrix3D op;
        {
            PROFILE("Matrix Multiplication");
            op = translator *  scale * rotator;
        }

        {
            PROFILE("Vector Transformation");
            for( unsigned int i = 0 ; i < 3 ; i++ ){
                transFormedshipVerts[i] = op * shipVerts[i];
            }

            Matrix3D translator2 = Matrix3D::translate( currentLerperPosition );
            op = translator2 * scale;
            for( unsigned int i = 3 ; i < 6 ; i++ ){
                transFormedshipVerts[i] = op * shipVerts[i];
            }

            for( unsigned int i = 6 ; i < NUM_shipVerts ; i++ ){
                transFormedshipVerts[i] = shipVerts[i];
            }
        }

        glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(transFormedshipVerts), transFormedshipVerts);
        glDrawElements(GL_LINES, 21, GL_UNSIGNED_SHORT, 0 );
        glDrawElements(GL_LINES, 21, GL_UNSIGNED_SHORT, 0 );
        is_updated = false;
    }
}

bool MyGLWindow::initialize()
{
    qDebug() << __func__ << endl;
    bool ret = true;
    profiler.initialize("profiles.csv");

    ret &= frameClock.initialize();

    return ret;
}

bool MyGLWindow::shutdown()
{
    qDebug() << __func__ << endl;

    bool ret = true;
    profiler.shutdown();

    ret &= frameClock.shutdown();

    return ret;

}

void MyGLWindow::updateVelocity(){

    Input::update();
    const float ACCELERATION = 0.0000002f * frameClock.lastlapTime();

    Vector3D directionToAccelerate( -sin(shipOrientation), cos(shipOrientation));

    if( Input::keyPressed( Qt::Key_Up )){

        shipVelocity += directionToAccelerate * ACCELERATION;

    }
}

void MyGLWindow::checkBounderies(){

    for( uint i = 0 ; i < NUM_BOUNDARY_VERTS ; i++){

        const Vector3D& first  = bounderyVerts[i];
        const Vector3D& second = bounderyVerts[( i + 1 ) % NUM_BOUNDARY_VERTS ];

        Vector3D wall = second - first;
        Vector3D normal = wall.perpCcwXy();
        Vector3D respectiveShipPosition = shipPosition - first;

        float dotResult = normal.dot( respectiveShipPosition );

        if( dotResult < 0 ){

            shipVelocity = shipVelocity - 2 * shipVelocity.projectOnto(normal);
            shipPosition = oldShipPosition;
        }
    }
}

void MyGLWindow::rotateShip(){

    Input::update();
    const float ANGULAR_MOVEMENT = 0.02f;

    if( Input::keyPressed(Qt::Key_Right) ){

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
