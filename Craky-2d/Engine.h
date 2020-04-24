#pragma once
#include "Phys.h"

const float dTime = 0.016f;
const unsigned int FrameDelay = 16;
const float Gravity = -9.81f;

const unsigned int Width = 500;
const unsigned int Height = 500;

extern PhysObj* Objects[10];
extern unsigned int _objects;

void AddGameObject(PhysObj* Obj);