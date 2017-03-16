#include "Robot.h"

//AUTO MODE INCLUDE
#include "Commands/Autonomous/DoNothingAuto.h"
#include "Commands/Autonomous/GearAlignCenter.h"
#include "Commands/Autonomous/GearAlignLeft.h"
#include "Commands/Autonomous/GearAlignRight.h"


#include "Commands/Leds/SetLeds.h"

std::shared_ptr<DrivebaseSubsystem> Robot::drivebaseSubsystem;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::shared_ptr<GearSubsystem> Robot::gearSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::shared_ptr<LedSubsystem> Robot::ledSubsystem;
std::shared_ptr<NetworkTable> Robot::visionTable;
std::shared_ptr<OI> Robot::oi;

DriverStation::Alliance Robot::currentAlliance;
bool Robot::doBoiler;
bool Robot::doCamera;
int isDataPassed;
bool isDifferent;

void Robot::RobotInit() {
	Command* ledCommand;
	RobotMap::init();

	isDataPassed = 0;
	isDifferent =  true;

    drivebaseSubsystem.reset(new DrivebaseSubsystem());
    shooterSubsystem.reset(new ShooterSubsystem());
    gearSubsystem.reset(new GearSubsystem());
    climberSubsystem.reset(new ClimberSubsystem());
    ledSubsystem.reset(new LedSubsystem());

	oi.reset(new OI());

	SmartDashboard::PutNumber("Shooter RPM", 4200);
	SmartDashboard::PutNumber("Loader RPM", 3000);

	currentAlliance = DriverStation::GetInstance().GetAlliance();

	doBoiler = true;
	doCamera = false;

	SmartDashboard::PutBoolean("Do Boiler", doBoiler);
	SmartDashboard::PutBoolean("Do Camera", doCamera);

	doBoiler = SmartDashboard::GetBoolean("Do Boiler", true);
	doCamera = SmartDashboard::GetBoolean("Do Camera", false);

	autoChooser.AddDefault("Do Nothing", new DoNothingAuto(15));
	autoChooser.AddObject("Gear Align Center", new GearAlignCenter());
	autoChooser.AddObject("Gear Align Right", new GearAlignRight());
	autoChooser.AddObject("Gear Align Left", new GearAlignLeft());

	SmartDashboard::PutData("Auto Mode Chooser", &autoChooser);

	SmartDashboard::PutNumber("minH", 44);
	SmartDashboard::PutNumber("minS", 163);
	SmartDashboard::PutNumber("minV", 83);
	SmartDashboard::PutNumber("maxH", 80);
	SmartDashboard::PutNumber("maxS", 255);
	SmartDashboard::PutNumber("maxV", 255);

	double minH = SmartDashboard::GetNumber("minH", 44);
	double minS = SmartDashboard::GetNumber("minS", 163);
	double minV = SmartDashboard::GetNumber("minV", 83);
	double maxH = SmartDashboard::GetNumber("maxH", 80);
	double maxS = SmartDashboard::GetNumber("maxS", 255);
	double maxV = SmartDashboard::GetNumber("maxV", 255);

	Robot::drivebaseSubsystem->ZeroYaw();
	Robot::drivebaseSubsystem->SetAdjYaw(0);

	visionTable = NetworkTable::GetTable("vision");
	visionTable->PutNumber("minH", minH);
	visionTable->PutNumber("minS", minS);
	visionTable->PutNumber("minV", minV);
	visionTable->PutNumber("maxH", maxH);
	visionTable->PutNumber("maxS", maxS);
	visionTable->PutNumber("maxV", maxV);

	ledCommand = new SetLeds("03", 0);
	ledCommand->Run();


}

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
	double minH = SmartDashboard::GetNumber("minH", 44);
	double minS = SmartDashboard::GetNumber("minS", 163);
	double minV = SmartDashboard::GetNumber("minV", 83);
	double maxH = SmartDashboard::GetNumber("maxH", 80);
	double maxS = SmartDashboard::GetNumber("maxS", 255);
	double maxV = SmartDashboard::GetNumber("maxV", 255);

	visionTable = NetworkTable::GetTable("vision");
	visionTable->PutNumber("minH", minH);
	visionTable->PutNumber("minS", minS);
	visionTable->PutNumber("minV", minV);
	visionTable->PutNumber("maxH", maxH);
	visionTable->PutNumber("maxS", maxS);
	visionTable->PutNumber("maxV", maxV);
}

void Robot::AutonomousInit() {
	Command* ledCommand;
	if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue)
		{
			ledCommand = new SetLeds("2", 0);
			ledCommand->Run();


		}
	else
	{
		ledCommand =  new SetLeds("1",  0);
		ledCommand->Run();

	}


	doBoiler = SmartDashboard::GetBoolean("Do Boiler", true);
	doCamera = SmartDashboard::GetBoolean("Do Camera", false);

	selectedMode.reset(autoChooser.GetSelected());
	if(selectedMode != nullptr){
		selectedMode->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	Command* ledCommand;
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue)
			{
				ledCommand = new SetLeds("2", 0);
				ledCommand->Run();


			}
		else
		{
			ledCommand =  new SetLeds("1",  0);
			ledCommand->Run();

		}

	Robot::shooterSubsystem->RunLoaderMotor(0);
	Robot::shooterSubsystem->RunShooterMotor(0);

	Robot::climberSubsystem->RunLeftTalon(0);
	Robot::climberSubsystem->RunRightTalon(0);

	Robot::shooterSubsystem->SetServoAngle(0);
	Robot::shooterSubsystem->SetHopperServoAngle(0);

	isDataPassed = 0;
	isDifferent = true;

	if (selectedMode != nullptr) {
		selectedMode->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("centerX", visionTable->GetNumber("centerX", 0.0));
	SmartDashboard::PutNumber("centerY", visionTable->GetNumber("centerY", 0.0));
	SmartDashboard::PutNumber("Live Shooter Rpm", RobotMap::shooterSubsystemFlywheelTalon->GetSpeed());
	SmartDashboard::PutNumber("Live Loader Rpm", RobotMap::shooterSubsystemLoaderTalon->GetSpeed());
	Command* ledCommand;

		if(gearSubsystem.get()->GetPressurePlateState()  && isDifferent)
		{
			isDataPassed = 0;
			ledCommand = new SetLeds("20", isDataPassed);
			ledCommand->Run();
			isDifferent  = false;
		}
		else if(!gearSubsystem.get()->GetPressurePlateState())
		{
			ledCommand = new SetLeds("21", isDataPassed);
			ledCommand->Run();
			//if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue)
			//{
			//	ledCommand = new SetLeds("27", isDataPassed); //Need to change the Arduino code to have solid blue
			//	ledCommand->Run();
			//}
			//else
			//{
			//	ledCommand =  new SetLeds("28",  isDataPassed); //Need to change the Arduino code to have solid red
			//	ledCommand->Run();
			//}
			isDataPassed = 1;
			isDifferent  = true;
		}
		else
		{
			//std::cout << "Third Case!" << std::endl;
		}
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
