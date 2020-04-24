#include "Phys.h"
#include "Engine.h"

void PhysObj::ApplyGravity() {
	if (_gravity) { LinearVelocity->Y += Gravity * Weight * dTime; }
}

void PhysObj::PerfromNormalTick() {
 	ApplyGravity();
	UpdatePosition();
}

void PhysObj::UpdatePosition() {
	ShiftShape(LinearVelocity->X * dTime, LinearVelocity->Y * dTime);
}

void PhysObj::PerformCollisionTick(PhysObj* Collision, Point* At) {
	float TotalWeight = Weight + Collision->Weight;

	Point* sumMomentum = new Point(
		((LinearVelocity->X * Weight) + (Collision->LinearVelocity->X * Collision->Weight)) / TotalWeight,
		(((LinearVelocity->Y * Weight) + (Collision->LinearVelocity->Y * Collision->Weight)) / TotalWeight));

	if (Weight>Collision->Weight) sumMomentum->Y += Gravity* Weight * dTime;
	else sumMomentum->Y += Gravity * Collision->Weight * dTime;

	LinearVelocity = new Point(sumMomentum->X, sumMomentum->Y);
	Collision->LinearVelocity = new Point(sumMomentum->X, sumMomentum->Y);

	UpdatePosition();
	Collision->UpdatePosition();
}

void PhysObj::ChangeLinearVelocity(Point* Change) {
	LinearVelocity->X += Change->X;
	LinearVelocity->Y += Change->Y;
}