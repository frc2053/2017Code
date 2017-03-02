#include "LoaderServo.h"

LoaderServo::LoaderServo(float angle) {
	Requires(Robot::shooterSubsystem.get());
	_angle = angle;
	isDone = false;
}

void LoaderServo::Initialize() {
	_angle = 90;
}

void LoaderServo::Execute() {
	Robot::shooterSubsystem->SetServoAngle(_angle);
	isDone = true;
}

bool LoaderServo::IsFinished() {
	return isDone;
}

void LoaderServo::End() {

}

void LoaderServo::Interrupted() {

}
