#include "ChuteSolenoid.h"

ChuteSolenoid::ChuteSolenoid(bool direction) {
	Requires(Robot::gearSubsystem.get());
	isDone = false;
	currentDirection = direction;
}

void ChuteSolenoid::Initialize() {
	isDone = false;
}

void ChuteSolenoid::Execute() {
	if(currentDirection == 1) {
		Robot::gearSubsystem->SetChuteForward();
	}
	if(currentDirection == 0) {
		Robot::gearSubsystem->SetChuteBack();
	}
	isDone = true;
}

bool ChuteSolenoid::IsFinished() {
	return isDone;
}

void ChuteSolenoid::End() {

}

void ChuteSolenoid::Interrupted() {

}
