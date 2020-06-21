#include "mygame.h"
#include <Rendering/Renderable.h>

MyGame::MyGame(QObject *parent) : QObject(parent)
{

}

bool MyGame::initialize()
{
    Geometry* shipGeometry =
            renderer.addGeometry(
                shipVerts, numShipVerts, shipIndices, numShipIndices
                );

    shipInstance = renderer.addRenderable(shipGeometry);
    lerpInstance = renderer.addRenderable(shipGeometry);

}

void MyGame::update()
{
    shipInstance->where =
    lerpInstance->where =

}
