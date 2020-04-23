#include "Phys.h"

void PhysObj::ApplyGravity() {
	LinearVelocity->Y += Gravity * Weight * dTime;
}

void PhysObj::PerfromTick() {
	ShiftShape(LinearVelocity->X * dTime, LinearVelocity->Y * dTime);
}