#include "ShooterSubsystem.h"
#include "../RobotMap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem") {
	flywheelTalon = RobotMap::shooterSubsystemFlywheelTalon;
	loaderTalon = RobotMap::shooterSubsystemLoaderTalon;
	turretTalon = RobotMap::shooterSubsystemTurretTalon;
}

void ShooterSubsystem::InitDefaultCommand() {
	flywheelTalon->Set(0);
	loaderTalon->Set(0);
	turretTalon->Set(0);
}

void ShooterSubsystem::RunShooterMotor(float rpm) {

	flywheelTalon->Set(rpm);
}

void ShooterSubsystem::RunLoaderMotor(float rpm){
	loaderTalon->Set(rpm);
}

void ShooterSubsystem::RunTurretMotor(float pos) {
	turretTalon->Set(pos);
}

double ShooterSubsystem::GetAngleOfTurret() {
	return turretTalon->GetPosition();
}
