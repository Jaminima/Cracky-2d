#include "Engine.h"

PhysObj* Objects[10];
unsigned int _objects = 0;

void AddGameObject(PhysObj* Obj) {
    Objects[_objects] = Obj;
    _objects++;
}

void DoPhysicsTick() {
    for (unsigned int i = 0; i < _objects; i++) Objects[i]->PerfromNormalTick();

    Point* CollisionAt;
    for (unsigned int i = 0, j = 1; i < _objects; i++) {
        CollisionAt = Objects[i]->CollidesWith(Objects[j]);

        if (CollisionAt != 0x0) Objects[i]->PerformCollisionTick(Objects[j], CollisionAt);

        j++;
        if (j == _objects) { i++; j = i + 1; }
    }
}