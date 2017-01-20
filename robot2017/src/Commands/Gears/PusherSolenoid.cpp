#include "PusherSolenoid.h"

PusherSolenoid::PusherSolenoid(bool input) {
	Requires(Robot::gearSubsystem.get());
	direction = input;
	isDone = false;
}

void PusherSolenoid::Initialize() {
	isDone = false;
	direction = 0;
}

void PusherSolenoid::Execute() {
	if(direction == 0) {
		Robot::gearSubsystem->SetPusherBack();
	}
	else {
		Robot::gearSubsystem->SetPusherForward();
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
