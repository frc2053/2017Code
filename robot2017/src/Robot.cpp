#include "Robot.h"

std::shared_ptr<DrivebaseSubsystem> Robot::drivebaseSubsystem;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();
    drivebaseSubsystem.reset(new DrivebaseSubsystem());

	oi.reset(new OI());

	Robot::drivebaseSubsystem->ZeroYaw();


}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
