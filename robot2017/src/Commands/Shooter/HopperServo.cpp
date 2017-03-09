#include "HopperServo.h"

HopperServo::HopperServo(float time) {
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
}

void HopperServo::Initialize() {
}

void HopperServo::Execute() {
	isDone = false;
	timeCurrent = timer->Get();
	if(timeCurrent >= timeTarget)
	{
		Robot::shooterSubsystem->SetHopperServoAngle(180);
		frc::Wait(timeTarget);
		timer->Reset();
		timer->Start();
	}
	else {
		Robot::shooterSubsystem->SetHopperServoAngle(0);
	}
}

bool HopperServo::IsFinished() {
	return isDone;
}

void HopperServo::End() {

}

void HopperServo::Interrupted() {

}
