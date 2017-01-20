#include "Robot.h"

//AUTO MODE INCLUDE
#include "Commands/Autonomous/DoNothingAuto.h"
#include "Commands/Autonomous/GearAlign.h"

std::shared_ptr<DrivebaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::shared_ptr<GearSubsystem> Robot::gearSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<NetworkTable> Robot::visionTable;

void Robot::RobotInit() {
	RobotMap::init();
    drivebaseSubsystem.reset(new DrivebaseSubsystem());
    shooterSubsystem.reset(new ShooterSubsystem());
    gearSubsystem.reset(new GearSubsystem());
    climberSubsystem.reset(new ClimberSubsystem());


	oi.reset(new OI());

	autoChooser.AddDefault("Do Nothing", new DoNothingAuto(15));
	autoChooser.AddObject("Gear Align", new GearAlign());

	SmartDashboard::PutData("Auto Mode Chooser", &autoChooser);

	Robot::drivebaseSubsystem->ZeroYaw();
	visionTable = NetworkTable::GetTable("vision");
}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	selectedMode.reset(autoChooser.GetSelected());
	if(selectedMode != nullptr){
		selectedMode->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (selectedMode != nullptr) {
		selectedMode->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("centerX", visionTable->GetNumber("centerX", 0.0));
	SmartDashboard::PutNumber("centerY", visionTable->GetNumber("centerY", 0.0));
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
