#include "myglwindow.h"
#include <QApplication>
#include <QElapsedTimer>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setMajorVersion(2);
    format.setMinorVersion(1);

    MyGLWindow window;
    window.setFormat(format);
    window.resize(QSize( 800, 600 ));

    if(!window.initialize())
        return -1;

    window.show();

    int errorCode = a.exec();
    if( !window.shutdown())
        errorCode |= 1;

    return errorCode;
}
