#include "Shape.h"

void Shape::ShiftShape(float dX, float dY) {
	for (int i = 0; i < tri_count; i++) Triangles[i]->ShiftPoints(dX, dY);
}

Point* Shape::CollidesWith(Shape* Other) {
	Point* P = 0x0;
	for (int T = 0, R = 0; R < Other->tri_count && P == 0x0;) {
		P = Triangles[T]->CollidesWith(Other->Triangles[R]);
		T++;
		if (T == tri_count) { T = 0; R++; }
	}
	return P;
}

void Shape::CalculateCenter() {
	int X = 0;
	int Y = 0;
	for (int i = 0; i < tri_count; i++) {
		X += Triangles[i]->Center->X;
		Y += Triangles[i]->Center->Y;
	}
	Center = new Point(X / tri_count, Y / tri_count);
}