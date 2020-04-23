#include "Main.h"

int main()
{
    PhysObj* O1 = new PhysObj(1);
    PhysObj* O2 = new PhysObj(1);

    Triangle* p = new Triangle();
    Triangle* q = new Triangle();

    p->Vertexes[0] = new Point(0, 0);
    p->Vertexes[1] = new Point(5, 5);
    p->Vertexes[2] = new Point(10, 0);

    q->Vertexes[0] = new Point(0, 10);
    q->Vertexes[1] = new Point(5, 5);
    q->Vertexes[2] = new Point(10, 10);

    O1->Triangles[0] = p;
    O2->Triangles[0] = q;

    O1->ShiftShape(0,20);

    while (!O1->CollidesWith(O2)) {
        O1->ApplyGravity();
        O1->PerfromTick();
    }
}