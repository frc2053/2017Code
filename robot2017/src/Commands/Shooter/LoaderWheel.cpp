#include "LoaderWheel.h"

LoaderWheel::LoaderWheel(float speed, float time) {
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	inputSpeed = speed;
	timer->Reset();
	timer->Start();
}

void LoaderWheel::Initialize() {
	isDone = false;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
}

void LoaderWheel::Execute()
{
	inputSpeed = SmartDashboard::GetNumber("Loader RPM", 3000);
	timeCurrent = timer->Get();
	if(timeTarget == 0)
	{
		Robot::shooterSubsystem->RunLoaderMotor(inputSpeed);
		isDone = true;
	}
	else
	{
		if(timeCurrent >= timeTarget)
		{
			Robot::shooterSubsystem->RunLoaderMotor(0);
			isDone = true;
		}
		else
		{
			Robot::shooterSubsystem->RunLoaderMotor(inputSpeed);
			isDone = false;
		}
	}
}

bool LoaderWheel::IsFinished() {
	return isDone;
}

void LoaderWheel::End() {
	timer->Stop();
}

void LoaderWheel::Interrupted() {
	timer->Stop();
}
