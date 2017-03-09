#include "HopperServo.h"

HopperServo::HopperServo(float angle) {
	Requires(Robot::shooterSubsystem.get());
	_angle = angle;
	isDone = false;
}

void HopperServo::Initialize() {
	_angle = 0;
}

void HopperServo::Execute() {
	Robot::shooterSubsystem->SetServoAngle(_angle);
	isDone = true;
}

bool HopperServo::IsFinished() {
	return isDone;
}

void HopperServo::End() {

}

void HopperServo::Interrupted() {

}
