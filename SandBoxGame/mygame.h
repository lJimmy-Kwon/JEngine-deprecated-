#ifndef MYGAME_H
#define MYGAME_H

#include <QObject>
#include <Rendering/renderer.h>
namespace Rendering { class Renderable; }

class MyGame : public QObject
{
    Q_OBJECT

    Rendering::Renderer renderer;
    Rendering::Renderable* shipInstance;
    Rendering::Renderable* lerpInstance;

public:
    explicit MyGame(QObject *parent = nullptr);
    bool initialize();
    void update();

};

#endif // MYGAME_H
