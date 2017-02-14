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
	inputSpeed = SmartDashboard::GetNumber("Shooter RPM", 4000);
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		Robot::shooterSubsystem->RunShooterMotor(inputSpeed);
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::shooterSubsystem->RunShooterMotor(0);
			isDone = true;
		}
		else {
			Robot::shooterSubsystem->RunShooterMotor(inputSpeed);
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
	timer->Stop();
}

