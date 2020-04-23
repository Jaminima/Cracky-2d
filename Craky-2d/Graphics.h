#pragma once
#include <stdlib.h>
#include "GL/glut.h"
#include "Main.h"

const unsigned int Width = 500;
const unsigned int Height = 500;

void SetupWindow(int argc, char** argv);

void Frame();

void Idle();

void DrawFrames();

void DrawObject(PhysObj* Object);

void DrawTriangle(Triangle* Tri);

void AddObjectToRender(PhysObj* Obj);