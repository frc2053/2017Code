#include "../Shooter/ShooterWheel.h"

ShooterWheel::ShooterWheel(float speed, float time) {
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	inputSpeed = speed;
	timer->Reset();
	timer->Start();
}

void ShooterWheel::Initialize() {
	isDone = false;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
}

void ShooterWheel::Execute() {
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		Robot::shooterSubsystem->RunMotor(inputSpeed);
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::shooterSubsystem->RunMotor(0);
			isDone = true;
		}
		else {
			Robot::shooterSubsystem->RunMotor(inputSpeed);
			isDone = false;
		}
	}
}

bool ShooterWheel::IsFinished() {
	return isDone;
}

void ShooterWheel::End() {
	timer->Stop();
}

void ShooterWheel::Interrupted() {

}