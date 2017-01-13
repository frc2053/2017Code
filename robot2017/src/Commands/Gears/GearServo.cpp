#include "GearServo.h"

GearServo::GearServo(float inputAngle) {
	Requires(Robot::servosSubsystem.get());
	angle = inputAngle;
	isDone = false;
}

void GearServo::Initialize() {
	isDone = false;
}

void GearServo::Execute() {
	Robot::servosSubsystem->SetAngleGearLoaderServos(angle);
	isDone = true;
}

bool GearServo::IsFinished() {
	return isDone;
}

void GearServo::End() {

}

void GearServo::Interrupted() {

}
