#include "FlapperSolenoid.h"

FlapperSolenoid::FlapperSolenoid(bool mode, bool direction) {
	Requires(Robot::gearSubsystem.get());
	isDone = false;
	currentMode = mode;
	currentDirection = direction;
}

void FlapperSolenoid::Initialize() {
	isDone = false;
	currentMode = 0;
	currentDirection = 0;
}

void FlapperSolenoid::Execute() {
	if(currentMode == 0) {
		if(Robot::gearSubsystem->GetFlapperState() == DoubleSolenoid::kForward) {
			Robot::gearSubsystem->SetFlapperDown();
		}
		else {
			Robot::gearSubsystem->SetFlapperUp();
		}
		isDone = true;
	}
	else {
		if(currentDirection == 1) {
			Robot::gearSubsystem->SetFlapperUp();
		}
		if(currentDirection == 0) {
			Robot::gearSubsystem->SetFlapperDown();
		}
		isDone = true;
	}
}

bool FlapperSolenoid::IsFinished() {
	return isDone;
}

void FlapperSolenoid::End() {
}

void FlapperSolenoid::Interrupted() {
}
