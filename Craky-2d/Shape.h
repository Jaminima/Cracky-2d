#pragma once

struct Point {
public:
	float X = 0;
	float Y = 0;

	Point(float X, float Y) {
		this->X = X;
		this->Y = Y;
	}
};

class Triangle {
public:
	Point* Vertexes[3];

	Point* CollidesWith(Triangle* Other);

	Point* LineCollides(Point* S1, Point* S2, Point* R1, Point* R2);

	void ShiftPoints(float dX, float dY);

	bool ValueBetween(float V, float B1, float B2);
};

class Shape {
public:
	Triangle** Triangles;
	unsigned int tri_count = 0;

	Shape(unsigned int t_count) {
		tri_count = t_count;
		Triangles = new Triangle*[tri_count];
	}

	void ShiftShape(float dX, float dY);

	Point* CollidesWith(Shape* Other);
};