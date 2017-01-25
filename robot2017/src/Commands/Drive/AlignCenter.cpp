#include "AlignCenter.h"

AlignCenter::AlignCenter(float inputAngle)
{
	Requires(Robot::drivebaseSubsystem.get());
	distanceToCenter = 0;
	adjyaw = 0;
	isDone = false;
	speedX = 0;
	std::cout << "Align Constructor" << std::endl;
	gearAngle = inputAngle;
}

void AlignCenter::Initialize()
{
	std::cout << "Align Init" << std::endl;
	distanceToCenter = 0;
	adjyaw = 0;
	isDone = false;
	speedX = 0;
}

void AlignCenter::Execute()
{
	std::cout << "Align Execute" << std::endl;
	adjyaw = Robot::drivebaseSubsystem->GetAdjYaw();
	distanceToCenter = (320 / 2) - Robot::visionTable->GetNumber("centerX", 0.0);
	SmartDashboard::PutNumber("distanceToCenter", distanceToCenter);


	if(fabs(Robot::oi->GetLeftXAxisDriver()) > .1 || fabs(Robot::oi->GetLeftYAxisDriver()) > .1 || fabs(Robot::oi->GetRightXAxisDriver()) > .1) {
		std::cout << "Override!" << std::endl;
		this->Cancel();
		isDone = true;
	}

	speedX = CalculateSpeedValue(distanceToCenter);
	std::cout << "speedX: " << speedX << std::endl;

	float rot = Robot::drivebaseSubsystem->CalculateRotValue(gearAngle, 1);
	Robot::drivebaseSubsystem->MecanumDrive(speedX, 0, rot, adjyaw);
	std::cout << "isDone: " <<  isDone << std::endl;
}

bool AlignCenter::IsFinished()
{
	std::cout << "Align IsFinished" << std::endl;
	return isDone;
}

void AlignCenter::End()
{
	std::cout << "Align End" << std::endl;
}

void AlignCenter::Interrupted()
{
	std::cout << "Align Interrupted" << std::endl;
}

float AlignCenter::CalculateSpeedValue(int distToCenter) {
	float returnedSpeed = 0;
	if(distToCenter > 2) {
		returnedSpeed = -.20;
		isDone = false;
	}

	if(distToCenter < -2 ) {
		returnedSpeed = .20;
		isDone = false;
	}

	if(abs(distToCenter) <= 2) {
		returnedSpeed = 0;
		isDone = true;
	}

	return returnedSpeed;
}
