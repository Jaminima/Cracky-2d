#include "Engine.h"

PhysObj* Objects[10];
unsigned int _objects = 0;

void AddGameObject(PhysObj* Obj) {
    Objects[_objects] = Obj;
    _objects++;
}

void DoPhysicsTick() {
    PhysObj* CollidesWith = 0x0;
    Point* CollidesAt = 0x0;
    for (int i = 0; i < _objects; i++) {

        for (int j = 0; j < _objects; j++) {
            CollidesAt = Objects[i]->CollidesWith(Objects[j]);
            if (CollidesAt != 0x0 && j!=i) { CollidesWith = Objects[j]; break; }
        }

        if (CollidesWith == 0x0) Objects[i]->PerfromNormalTick();
        else Objects[i]->PerformCollisionTick(CollidesWith, CollidesAt);
    }
}