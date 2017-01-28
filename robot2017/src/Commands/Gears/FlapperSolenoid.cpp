#include "FlapperSolenoid.h"

FlapperSolenoid::FlapperSolenoid(bool direction) {
	Requires(Robot::gearSubsystem.get());
	isDone = false;
	currentDirection = direction;
}

void FlapperSolenoid::Initialize() {
	isDone = false;
}

void FlapperSolenoid::Execute() {
	if(currentDirection == 1) {
		Robot::gearSubsystem->SetFlapperUp();
	}
	if(currentDirection == 0) {
		Robot::gearSubsystem->SetFlapperDown();
	}
	isDone = true;
}

bool FlapperSolenoid::IsFinished() {
	return isDone;
}

void FlapperSolenoid::End() {
}

void FlapperSolenoid::Interrupted() {
}
