#include "LoaderWheel.h"
#include "HopperServo.h"

LoaderWheel::LoaderWheel(float speed, float time) {
	Requires(Robot::shooterSubsystem.get());
	//timer.reset(new Timer());
	isDone = false;
	//timeTarget = time;
	//timeCurrent = 0;
	inputSpeed = speed;
	//timer->Reset();
	//timer->Start();
	hopperServoCmd = new HopperServo(.5);
	Scheduler::GetInstance()->AddCommand(hopperServoCmd);
}

void LoaderWheel::Initialize() {
	isDone = false;
	//timeCurrent = 0;
	//timer->Reset();
	//timer->Start();
}

void LoaderWheel::Execute()
{
	isDone = false;
	if(inputSpeed == 0)
	{
		Robot::shooterSubsystem->RunLoaderMotor(0);
		isDone = true;
	}

	if(!inputSpeed == 0) {
		inputSpeed = SmartDashboard::GetNumber("Loader RPM", 3000);
	}

	//timeCurrent = timer->Get();

	//if(timeTarget == 0)
	//{
	//	Robot::shooterSubsystem->RunLoaderMotor(inputSpeed);
	//	isDone = false;
	//}

	//else
	//{
	//	if(timeCurrent >= timeTarget)
	//	{
	//		Robot::shooterSubsystem->RunLoaderMotor(0);
	//		isDone = true;
	//	}
	//	else {

			Robot::shooterSubsystem->RunLoaderMotor(inputSpeed);

<<<<<<< HEAD
		if(RobotMap::shooterSubsystemLoaderTalon->GetSpeed() > 3300) {
=======

		/*if(RobotMap::shooterSubsystemLoaderTalon->GetSpeed() > 2000) {
>>>>>>> origin/master
			Robot::shooterSubsystem->SetServoAngle(90);
		}*/
		//else {
			//Robot::shooterSubsystem->SetServoAngle(0);
		//}

			//isDone = false;
	//	}

	//}
}

bool LoaderWheel::IsFinished() {
	return isDone;
}

void LoaderWheel::End() {
	Robot::shooterSubsystem->RunLoaderMotor(0);
	Scheduler::GetInstance()->Remove(hopperServoCmd);
	//timer->Stop();
}

void LoaderWheel::Interrupted() {
	//timer->Stop();
}
