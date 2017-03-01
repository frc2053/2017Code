#include "LoaderServo.h"

LoaderServo::LoaderServo(float angle) {
	Requires(Robot::shooterSubsystem.get());
	_angle = angle;
}

void LoaderServo::Initialize() {
	_angle = 90;
}

void LoaderServo::Execute() {
	Robot::shooterSubsystem->SetServoAngle(_angle);
}

bool LoaderServo::IsFinished() {
	return true;
}

void LoaderServo::End() {

}

void LoaderServo::Interrupted() {

}
