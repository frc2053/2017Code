#include "HopperServo.h"

HopperServo::HopperServo(float time) {
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
	isDeployed = false;
}

void HopperServo::Initialize() {
	//std::cout << "MADE IT TO HOPPER SERVO INIT" << std::endl;
	isDeployed = false;
}

void HopperServo::Execute() {
	//std::cout << "." << std::endl;
	isDone = false;
	timeCurrent = timer->Get();

	if(timeTarget == 0)
	{
		isDone = true;
	}
	else
	{
		if(timeCurrent >= timeTarget)
		{
			//std::cout << "MADE IT TO THE HOPPER SERVO ANGLE 180" << std::endl;
			//Robot::shooterSubsystem->SetHopperServoAngle(180);
			//std::cout << "TIMER EXPIRED" << std::endl;
			isDeployed = !isDeployed;
			timer->Reset();
			timer->Start();
			frc::Wait(.01);

		}

		if(isDeployed) {
			//std::cout << "MADE IT TO THE HOPPER SERVO ANGLE 180" << std::endl;
			Robot::shooterSubsystem->SetHopperServoAngle(0);
		}
		else
		{
			//std::cout << "MADE IT TO THE HOPPER SERVO ANGLE 0" << std::endl;
			Robot::shooterSubsystem->SetHopperServoAngle(75);
		}

	}
}

bool HopperServo::IsFinished() {
	return isDone;
}

void HopperServo::End() {
	Robot::shooterSubsystem->SetHopperServoAngle(75);
	//std::cout << "HOPPER SERVO DONE" << std::endl;
}

void HopperServo::Interrupted() {

}
