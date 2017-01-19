#include "AlignCenter.h"

AlignCenter::AlignCenter()
{
	Requires(Robot::drivebaseSubsystem.get());
	distanceToCenter = 0;
	adjyaw = 0;
	isDone = false;
	speedX = 0;
}

void AlignCenter::Initialize()
{
	distanceToCenter = 0;
	adjyaw = 0;
	isDone = false;
	speedX = 0;
}

void AlignCenter::Execute()
{
	adjyaw = Robot::drivebaseSubsystem->GetAdjYaw();
	distanceToCenter = (320 / 2) - Robot::visionTable->GetNumber("centerX", 0.0);
	SmartDashboard::PutNumber("distanceToCenter", distanceToCenter);

	if(fabs(Robot::oi->GetLeftXAxisDriver()) > .1 || fabs(Robot::oi->GetLeftYAxisDriver()) > .1 || fabs(Robot::oi->GetRightXAxisDriver()) > .1) {
		isDone = true;
	}

	speedX = CalculateSpeedValue(distanceToCenter);

	float rot = Robot::drivebaseSubsystem->CalculateRotValue(0, 1);
	Robot::drivebaseSubsystem->MecanumDrive(speedX, 0, rot, adjyaw);
}

bool AlignCenter::IsFinished()
{
	return isDone;
}

void AlignCenter::End()
{
}

void AlignCenter::Interrupted()
{

}

float AlignCenter::CalculateSpeedValue(int distToCenter) {
	float returnedSpeed = 0;
	if(distToCenter >= 15) {
		returnedSpeed = -.20;
	}

	if(distToCenter <= -15) {
		returnedSpeed = .20;
	}

	if(abs(distToCenter) < 1) {
		returnedSpeed = 0;
		isDone = true;
	}

	return returnedSpeed;
}
