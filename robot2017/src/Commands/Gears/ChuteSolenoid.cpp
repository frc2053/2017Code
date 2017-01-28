#include "ChuteSolenoid.h"

ChuteSolenoid::ChuteSolenoid(bool mode, bool direction) {
	Requires(Robot::gearSubsystem.get());
	isDone = false;
	currentMode = mode;
	currentDirection = direction;
}

void ChuteSolenoid::Initialize() {
	isDone = false;
	currentMode = 0;
	currentDirection = 0;
}

void ChuteSolenoid::Execute() {
	if(currentMode == 0) {
		if(Robot::gearSubsystem->GetChuteState() == DoubleSolenoid::kForward) {
			Robot::gearSubsystem->SetChuteBack();
		}
		else {
			Robot::gearSubsystem->SetChuteForward();
		}
		isDone = true;
	}
	else {
		if(currentDirection == 1) {
			Robot::gearSubsystem->SetChuteForward();
		}
		if(currentDirection == 0) {
			Robot::gearSubsystem->SetChuteBack();
		}
		isDone = true;
	}
}

bool ChuteSolenoid::IsFinished() {
	return isDone;
}

void ChuteSolenoid::End() {

}

void ChuteSolenoid::Interrupted() {

}
