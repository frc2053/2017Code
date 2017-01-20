#include "PusherSolenoid.h"

PusherSolenoid::PusherSolenoid(bool mode, bool direction) {
	Requires(Robot::gearSubsystem.get());
	isDone = false;
	currentMode = mode;
	currentDirection = direction;
}

void PusherSolenoid::Initialize() {
	isDone = false;
	currentMode = 0;
	currentDirection = 0;
}

void PusherSolenoid::Execute() {
	if(currentMode == 0) {
		if(Robot::gearSubsystem->GetPusherState() == DoubleSolenoid::kForward) {
			Robot::gearSubsystem->SetPusherBack();
		}
		else {
			Robot::gearSubsystem->SetPusherForward();
		}
		isDone = true;
	}
	else {
		if(currentDirection == 1) {
			Robot::gearSubsystem->SetPusherForward();
		}
		if(currentDirection == 0) {
			Robot::gearSubsystem->SetPusherBack();
		}
		isDone = true;
	}
}

bool PusherSolenoid::IsFinished() {
	return isDone;
}

void PusherSolenoid::End() {

}

void PusherSolenoid::Interrupted() {

}
