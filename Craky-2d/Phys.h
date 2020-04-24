#pragma once
#include "Shape.h"

class PhysObj : public Shape {
public:
	float Weight = 1;
	float AngularDrag = 1;
	float LinearDrag = 1;

	bool _gravity = true;

	Point* LinearVelocity = new Point(0, 0);
	float AngularVelocity = 0;

	void ApplyGravity();

	void ChangeLinearVelocity(Point* Change);

	void PerfromTick();

	PhysObj(unsigned int t_count) : Shape(t_count) { }
};