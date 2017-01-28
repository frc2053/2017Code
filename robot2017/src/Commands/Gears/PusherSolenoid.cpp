#include "PusherSolenoid.h"

PusherSolenoid::PusherSolenoid(bool direction) {
	Requires(Robot::gearSubsystem.get());
	isDone = false;
	currentDirection = direction;
}

void PusherSolenoid::Initialize() {
	isDone = false;
	currentDirection = 0;
}

void PusherSolenoid::Execute() {
	if(currentDirection == 1) {
		Robot::gearSubsystem->SetPusherForward();
	}
	if(currentDirection == 0) {
		Robot::gearSubsystem->SetPusherBack();
	}
	isDone = true;
}

bool PusherSolenoid::IsFinished() {
	return isDone;
}

void PusherSolenoid::End() {

}

void PusherSolenoid::Interrupted() {

}
