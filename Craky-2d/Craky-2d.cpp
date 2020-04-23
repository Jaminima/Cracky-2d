#include "Main.h"

int main()
{
    Shape* O1 = new Shape(1);
    Shape* O2 = new Shape(1);

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

    q = O1->Triangles[1];

    Point* P = O1->CollidesWith(O2);
}