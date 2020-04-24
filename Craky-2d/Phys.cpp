#include "Phys.h"
#include "Engine.h"

void PhysObj::ApplyGravity() {
	if (_gravity) { 
		LinearVelocity->Y += Gravity * Weight * dTime; }
}

void PhysObj::PerfromNormalTick() {
 	ApplyGravity();
	ShiftShape(LinearVelocity->X * dTime, LinearVelocity->Y * dTime);
}

void PhysObj::PerformCollisionTick(PhysObj* Collision, Point* At) {

}

void PhysObj::ChangeLinearVelocity(Point* Change) {
	LinearVelocity->X += Change->X;
	LinearVelocity->Y += Change->Y;
}