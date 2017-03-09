#include "ShooterSubsystem.h"
#include "../RobotMap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem") {
	flywheelTalon = RobotMap::shooterSubsystemFlywheelTalon;
	loaderTalon = RobotMap::shooterSubsystemLoaderTalon;
	loaderServo = RobotMap::shooterSubsystemLoaderServo;
	hopperServo = RobotMap::shooterSubsystemHopperServo;
}

void ShooterSubsystem::InitDefaultCommand() {
	flywheelTalon->Set(0);
	loaderTalon->Set(0);
	loaderServo->SetAngle(75);
	hopperServo->SetAngle(0);
}

void ShooterSubsystem::RunShooterMotor(float rpm) {

	flywheelTalon->Set(rpm);
}

void ShooterSubsystem::RunLoaderMotor(float rpm){
	loaderTalon->Set(rpm);
}

void ShooterSubsystem::SetServoAngle(float angle) {
	std::cout << "----------------" << std::endl;

	std::cout << angle  << std::endl;

	loaderServo->SetAngle(angle);

	std::cout << loaderServo->GetAngle() << std::endl;

	std::cout << "----------------" << std::endl;


}

void ShooterSubsystem::SetHopperServoAngle(float angle) {
	hopperServo->SetAngle(angle);
}

