#pragma once

struct Point {
public:
	float X = 0;
	float Y = 0;

	Point(float X, float Y) {
		this->X = X;
		this->Y = Y;
	}

	void Add (Point* P);
	void Sub (Point* P);
};

class Triangle {
public:
	Point* Center;

	Point* Vertexes[3];

	Point* CollidesWith(Triangle* Other);

	Point* LineCollides(Point* S1, Point* S2, Point* R1, Point* R2);

	void RotatePoints(float deg, Point* sCenter);

	void ShiftPoints(float dX, float dY);

	void CalculateCenter();

	bool ValueBetween(float V, float B1, float B2);
};

class Shape {
public:
	Point* Center = 0x0;
	Triangle** Triangles = 0x0;
	unsigned int tri_count = 0;

	Shape(unsigned int t_count) {
		tri_count = t_count;
		Triangles = new Triangle*[tri_count];
	}

	void CalculateCenter();

	void RotateShape(float deg);

	void ShiftShape(float dX, float dY);

	Point* CollidesWith(Shape* Other);
};