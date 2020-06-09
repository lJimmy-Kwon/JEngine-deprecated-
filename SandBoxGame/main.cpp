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
    window.show();

    return a.exec();
}
