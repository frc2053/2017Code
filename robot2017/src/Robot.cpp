#include "Robot.h"

std::shared_ptr<DrivebaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::shared_ptr<GearSubsystem> Robot::gearSubsystem;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<NetworkTable> Robot::visionTable;

void Robot::RobotInit() {
	RobotMap::init();
    drivebaseSubsystem.reset(new DrivebaseSubsystem());
    shooterSubsystem.reset(new ShooterSubsystem());
    gearSubsystem.reset(new GearSubsystem());


	oi.reset(new OI());

	Robot::drivebaseSubsystem->ZeroYaw();
	visionTable = NetworkTable::GetTable("vision");
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
	SmartDashboard::PutNumber("centerX", visionTable->GetNumber("centerX", 0.0));
	SmartDashboard::PutNumber("centerY", visionTable->GetNumber("centerY", 0.0));
	visionTable->GetNumber("centerY", 0.0);
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
