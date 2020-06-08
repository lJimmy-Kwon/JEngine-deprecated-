#include "myglwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(2, 1);

    MyGLWindow window;
    window.setFormat(format);
    window.resize(QSize( 800, 600 ));
    window.show();

    return a.exec();
}
