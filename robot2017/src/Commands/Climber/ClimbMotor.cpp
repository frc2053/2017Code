#include "ClimbMotor.h"

ClimbMotor::ClimbMotor(float speed, float time) {
	Requires(Robot::climberSubsystem.get());
	timer.reset(new Timer());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	inputSpeed = speed;
	timer->Reset();
	timer->Start();
}

void ClimbMotor::Initialize() {
	isDone = false;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
}

void ClimbMotor::Execute()
{
	timeCurrent = timer->Get();
	if(timeTarget == 0)
	{
		Robot::climberSubsystem->RunLeftTalon(inputSpeed);
		Robot::climberSubsystem->RunRightTalon(inputSpeed);
		isDone = true;
	}
	else
	{
		if(timeCurrent >= timeTarget)
		{
			Robot::climberSubsystem->RunLeftTalon(0);
			Robot::climberSubsystem->RunRightTalon(0);
			isDone = true;
		}
		else
		{
			Robot::climberSubsystem->RunRightTalon(inputSpeed);
			isDone = false;
		}
	}
}

bool ClimbMotor::IsFinished() {
	return isDone;
}

void ClimbMotor::End() {
	timer->Stop();
}

void ClimbMotor::Interrupted() {
	timer->Stop();
}
