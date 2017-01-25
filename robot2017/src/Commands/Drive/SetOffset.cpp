#include "SetOffset.h"

SetOffset::SetOffset(float input) {
	Requires(Robot::drivebaseSubsystem.get());
	isDone = false;
	inputYaw = input;
}

void SetOffset::Initialize() {
	isDone = false;
}

void SetOffset::Execute() {
	Robot::drivebaseSubsystem->SetAdjYaw(inputYaw);
	isDone = true;
}

bool SetOffset::IsFinished() {
	return isDone;
}

void SetOffset::End() {

}

void SetOffset::Interrupted() {

}
