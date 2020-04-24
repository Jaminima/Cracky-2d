#include "Graphics.h"

void DrawFrames() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    for (int i = 0; i < _objects; i++) DrawObject(Objects[i]);

    glEnd();

    glutSwapBuffers();
}

void DrawObject(PhysObj* Object) {
    for (unsigned int i = 0; i < Object->tri_count; i++) DrawTriangle(Object->Triangles[i]);
}

void DrawTriangle(Triangle* Tri) {
    glVertex2f(Tri->Vertexes[0]->X / Width, Tri->Vertexes[0]->Y / Height);
    //glColor3f(1, 0, 0);
    glVertex2f(Tri->Vertexes[1]->X / Width, Tri->Vertexes[1]->Y / Height);
    //glColor3f(0, 1, 0);
    glVertex2f(Tri->Vertexes[2]->X / Width, Tri->Vertexes[2]->Y / Height);
    //glColor3f(0, 0, 1);
}