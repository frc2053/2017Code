//DOES NOTHING
#include "DoNothingAuto.h"

DoNothingAuto::DoNothingAuto(float timeToWait)
{
	Requires(Robot::drivebaseSubsystem.get());
	timeTarget = timeToWait;
	timeCurrent = 0;
	timer.reset(new Timer());
	isDone = false;
}

void DoNothingAuto::Initialize()
{
	timeCurrent = 0;
	isDone = false;
	timer->Reset();
	timer->Start();
}

void DoNothingAuto::Execute()
{
	timeCurrent = timer->Get();
	if(timeCurrent >= timeTarget)
	{
		isDone = true;
	}
	else
	{
		isDone = false;
	}
}

bool DoNothingAuto::IsFinished()
{
	return isDone;
}

void DoNothingAuto::End()
{

}

void DoNothingAuto::Interrupted()
{

}
