#include "Engine.h"

PhysObj* Objects[10];
unsigned int _objects = 0;

void AddGameObject(PhysObj* Obj) {
    Objects[_objects] = Obj;
    _objects++;
}