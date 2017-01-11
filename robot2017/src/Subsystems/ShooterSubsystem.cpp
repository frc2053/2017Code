#include "ShooterSubsystem.h"
#include "../RobotMap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem") {
	flywheelTalon = RobotMap::shooterSubsystemFlywheelTalon;
}

void ShooterSubsystem::InitDefaultCommand() {

}

void ShooterSubsystem::RunMotor(float speed) {
	flywheelTalon->Set(speed);
}
