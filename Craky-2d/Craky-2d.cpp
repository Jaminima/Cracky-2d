#include "Main.h"

int main(int argc, char** argv)
{
    PhysObj* O1 = new PhysObj(1);
    PhysObj* O2 = new PhysObj(1);

    Triangle* p = new Triangle();
    Triangle* q = new Triangle();

    p->Vertexes[0] = new Point(-200, 70);
    p->Vertexes[1] = new Point(0, -80);
    p->Vertexes[2] = new Point(200, 70);

    p->CalculateCenter();

    q->Vertexes[0] = new Point(200, 200);
    q->Vertexes[1] = new Point(0, 80);
    q->Vertexes[2] = new Point(-200, 200);

    q->CalculateCenter();

    O1->Triangles[0] = p;
    O2->Triangles[0] = q;

    //O1->_gravity = false;
    O2->Weight = 1.1;

    O1->CalculateCenter();
    O2->CalculateCenter();

    AddGameObject(O1);
    AddGameObject(O2);

    SetupWindow(argc, argv);

    while (true) { std::getchar(); }
}