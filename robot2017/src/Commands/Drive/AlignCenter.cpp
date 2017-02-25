#include "AlignCenter.h"

AlignCenter::AlignCenter(float inputAngle)
{
	Requires(Robot::drivebaseSubsystem.get());
	distanceToCenter = 0;
	adjyaw = 0;
	isDone = false;
	speedX = 0;
	//std::cout << "Align Constructor" << std::endl;
	gearAngle = inputAngle;
	isRotDone = false;
	finalAutoRot = 0;
}

void AlignCenter::Initialize()
{
	//std::cout << "Align Init" << std::endl;
	distanceToCenter = 0;
	adjyaw = 0;
	isDone = false;
	speedX = 0;
	isRotDone = false;
	//Robot::ledSubsystem->SetRedLED(1);
	//Robot::ledSubsystem->SetGreenLED(0);
	//Robot::ledSubsystem->SetBlueLED(0);
}

void AlignCenter::Execute()
{
	//std::cout << "Align Execute" << std::endl;
	RobotMap::tigerDrive->turnController->SetSetpoint(gearAngle);
	adjyaw = Robot::drivebaseSubsystem->GetAdjYaw();
	isRotDone = Robot::drivebaseSubsystem->GetIsRotDone();
	finalAutoRot = Robot::drivebaseSubsystem->CalculateRotValue(gearAngle, 1);
	distanceToCenter = (320 / 2) - Robot::visionTable->GetNumber("centerX", 0.0);
	SmartDashboard::PutNumber("distanceToCenter", distanceToCenter);


	if(fabs(Robot::oi->GetLeftXAxisDriver()) > .1 || fabs(Robot::oi->GetLeftYAxisDriver()) > .1 || fabs(Robot::oi->GetRightXAxisDriver()) > .1) {
		std::cout << "Override!" << std::endl;
		this->Cancel();
		isDone = true;
	}


	speedX = CalculateSpeedValue(distanceToCenter);
	std::cout << "speedX: " << speedX << std::endl;


	if(speedX == 0 || abs(distanceToCenter) <= 2) {
		//Robot::ledSubsystem->SetRedLED(0);
		//Robot::ledSubsystem->SetGreenLED(0);
		//Robot::ledSubsystem->SetBlueLED(1);
		Robot::drivebaseSubsystem->MecanumDrive(0, 0, 0, 0);
		isDone = true;
		std::cout << "DONE WITH ALIGNMENT!" << std::endl;
	}
	else {
		Robot::drivebaseSubsystem->MecanumDrive(speedX, 0, finalAutoRot, adjyaw);
		isDone = false;
	}

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
		returnedSpeed = -.2;
		isDone = false;
	}

	if(distToCenter < -2 ) {
		returnedSpeed = .2;
		isDone = false;
	}

	if(abs(distToCenter) <= 2) {
		returnedSpeed = 0;
		isDone = true;
	}

	return returnedSpeed;
}
