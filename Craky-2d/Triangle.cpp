#include "Shape.h"

Point* Triangle::LineCollides(Point* S1, Point* S2, Point* R1, Point* R2){
	float sGrad = (S2->Y - S1->Y) / (S2->X - S1->X);
	float rGrad = (R2->Y - R1->Y) / (R2->X - R1->X);

	float sC = S1->Y - (sGrad * S1->X);
	float rC = R1->Y - (rGrad * R1->X);

	float xIntersect = (rC - sC) / (sGrad - rGrad);

	if (ValueBetween(xIntersect, S1->X, S2->X) && ValueBetween(xIntersect, R1->X, R2->X))
		return new Point(xIntersect, (sGrad * xIntersect) + sC);
	return 0x0;
};

Point* Triangle::CollidesWith(Triangle* Other) {
	Point* P = 0x0;
	for (int T = 0, R = 0; R < 3 && P == 0x0;) {
		P = LineCollides(this->Vertexes[T], this->Vertexes[(T + 1)%3], 
						Other->Vertexes[R], Other->Vertexes[(R + 1)%3]);
		T++;
		if (T == 3) { T = 0; R++; }
	}
	return P;
}

void Triangle::ShiftPoints(float dX, float dY) {
	for (int i = 0; i < 3; i++) {
		Vertexes[i]->X += dX;
		Vertexes[i]->Y += dY;
	}
}

void Triangle::CalculateCenter() {
	Center = new Point((Vertexes[0]->X + Vertexes[1]->X + Vertexes[2]->X) / 3,
		(Vertexes[0]->Y + Vertexes[1]->Y + Vertexes[2]->Y) / 3);
}

bool Triangle::ValueBetween(float V, float B1, float B2) {
	if (B2 > B1) return V <= B2&& B1 <= V;
	return V <= B1 && B2 <= V;
}