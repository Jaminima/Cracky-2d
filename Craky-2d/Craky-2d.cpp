#include "Main.h"

int main(int argc, char** argv)
{
    PhysObj* O1 = new PhysObj(1);
    PhysObj* O2 = new PhysObj(1);

    Triangle* p = new Triangle();
    Triangle* q = new Triangle();

    p->Vertexes[0] = new Point(-200, -200);
    p->Vertexes[1] = new Point(0, -80);
    p->Vertexes[2] = new Point(200, -200);

    q->Vertexes[0] = new Point(200, 200);
    q->Vertexes[1] = new Point(0, 80);
    q->Vertexes[2] = new Point(-200, 200);

    O1->Triangles[0] = p;
    O2->Triangles[0] = q;

    O1->ShiftShape(0,20);

    AddObjectToRender(O1);
    AddObjectToRender(O2);

    /*while (!O1->CollidesWith(O2)) {
        O1->ApplyGravity();
        O1->PerfromTick();
    }*/

    O2->ApplyGravity();

    SetupWindow(argc, argv);

    while (true) { std::getchar(); }

    /*DrawTriangle(p);
    DrawTriangle(q);*/
}