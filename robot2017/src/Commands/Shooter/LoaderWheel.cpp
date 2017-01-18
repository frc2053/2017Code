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

// Called just before this Command runs the first time
void LoaderWheel::Initialize() {
		printf("'\n'got to loader wheel initialize\n");
		isDone = false;
		timeCurrent = 0;
		timer->Reset();
		timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void LoaderWheel::Execute()
{
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

// Make this return true when this Command no longer needs to run execute()
bool LoaderWheel::IsFinished() {
	printf("'\n'got to the loader wheel is finished\n");
	return isDone;
}

// Called once after isFinished returns true
void LoaderWheel::End() {
	printf("'\n'got to the loader wheel end\n");
	Robot::shooterSubsystem->RunLoaderMotor(0);
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoaderWheel::Interrupted() {
	printf("'\n'loader wheel got interrupted\n");
	//Robot::shooterSubsystem->RunLoaderMotor(0);
	timer->Stop();
}
