#include "Phys.h"
#include "Engine.h"

void PhysObj::ApplyGravity() {
	LinearVelocity->Y += Gravity * Weight * dTime;
}

void PhysObj::PerfromTick() {
	ShiftShape(LinearVelocity->X * dTime, LinearVelocity->Y * dTime);
}

void PhysObj::ChangeLinearVelocity(Point* Change) {
	LinearVelocity->X += Change->X;
	LinearVelocity->Y += Change->Y;
}