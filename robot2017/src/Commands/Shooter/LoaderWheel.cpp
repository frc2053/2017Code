#include "LoaderWheel.h"
#include "HopperServo.h"
#include "../Leds/SetLeds.h"

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
	//std::cout << "ADDING NEW HOPPER SERVO COMMAND" << std::endl;
	Scheduler::GetInstance()->AddCommand(hopperServoCmd);
	isPassed = 0;
}

void LoaderWheel::Initialize() {
	//Command* ledCommand;

	//ledCommand = new SetLeds("16", 0);
	//ledCommand->Run();
	isDone = false;
	isPassed = 0;
	//timeCurrent = 0;
	//timer->Reset();
	//timer->Start();
}

void LoaderWheel::Execute()
{
	Command* ledCommand;

	isDone = false;
	if(inputSpeed == 0)
	{
		Robot::shooterSubsystem->RunLoaderMotor(0);
		Robot::shooterSubsystem->SetServoAngle(0);
		isDone = true;
	}

	if(!inputSpeed == 0) {
		inputSpeed = SmartDashboard::GetNumber("Loader RPM", 3000);
	}

	if(inputSpeed > 0 && isPassed == 0)
	{
		ledCommand = new SetLeds("17", isPassed);
		ledCommand->Run();
		isPassed = 1;
	}
	if(inputSpeed == 0 && isPassed == 0)
	{
		ledCommand = new SetLeds("16", isPassed);
		ledCommand->Run();
		isPassed = 1;
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

		//if(RobotMap::shooterSubsystemLoaderTalon->GetSpeed() > 2200) {
			Robot::shooterSubsystem->SetServoAngle(150);
	//	}
		/*if(RobotMap::shooterSubsystemLoaderTalon->GetSpeed() > 2000) {
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
	Robot::shooterSubsystem->SetServoAngle(0);
	//timer->Stop();
}

void LoaderWheel::Interrupted() {
	//timer->Stop();
}

