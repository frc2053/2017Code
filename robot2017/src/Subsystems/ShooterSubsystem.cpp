#include "ShooterSubsystem.h"
#include "../RobotMap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem") {
	flywheelTalon = RobotMap::shooterSubsystemFlywheelTalon;
	loaderTalon = RobotMap::shooterSubsystemLoaderTalon;
}

void ShooterSubsystem::InitDefaultCommand() {

}

void ShooterSubsystem::RunShooterMotor(float rpm) {

	flywheelTalon->Set(rpm);
}

void ShooterSubsystem::RunLoaderMotor(float speed){
	loaderTalon->Set(speed);
}

