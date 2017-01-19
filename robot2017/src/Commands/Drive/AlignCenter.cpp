#include "AlignCenter.h"

AlignCenter::AlignCenter()
{
	Requires(Robot::drivebaseSubsystem.get());
	distanceToCenter = 0;
	adjyaw = 0;
	isDone = false;
	speedX = 0;
}

// Called just before this Command runs the first time
void AlignCenter::Initialize()
{
	distanceToCenter = 0;
	adjyaw = 0;
	isDone = false;
	speedX = 0;
}

// Called repeatedly when this Command is scheduled to run
void AlignCenter::Execute()
{
	adjyaw = Robot::drivebaseSubsystem->GetAdjYaw();
	distanceToCenter = (320 / 2) - Robot::visionTable->GetNumber("centerX", 0.0);
	SmartDashboard::PutNumber("distanceToCenter", distanceToCenter);

	std::cout << "X: " << abs(Robot::oi->GetLeftXAxisDriver()) << std::endl;
	std::cout << "Y: " << abs(Robot::oi->GetLeftYAxisDriver()) << std::endl;
	std::cout << "Z: " << abs(Robot::oi->GetRightXAxisDriver()) << std::endl;

	if(fabs(Robot::oi->GetLeftXAxisDriver()) > .1 || fabs(Robot::oi->GetLeftYAxisDriver()) > .1 || fabs(Robot::oi->GetRightXAxisDriver()) > .1) {
		isDone = true;
		std::cout << "Override!" << std::endl;
	}

	speedX = CalculateSpeedValue(distanceToCenter);

	float rot = Robot::drivebaseSubsystem->CalculateRotValue(0, 1);
	Robot::drivebaseSubsystem->MecanumDrive(speedX, 0, rot, adjyaw);
}

// Make this return true when this Command no longer needs to run execute()
bool AlignCenter::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void AlignCenter::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
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
