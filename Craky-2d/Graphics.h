#pragma once
#include <stdlib.h>
#include "GL/glut.h"
#include "Engine.h"

void SetupWindow(int argc, char** argv);

void Frame();

void Idle();

void TriggerRedraw(int i);

void DrawFrames();

void DrawObject(PhysObj* Object);

void DrawTriangle(Triangle* Tri);