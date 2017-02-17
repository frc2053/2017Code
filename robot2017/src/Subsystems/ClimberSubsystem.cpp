#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem") {
	leftTalon = RobotMap::climberSubsystemLeftTalon;
	rightTalon = RobotMap::climberSubsystemRightTalon;
}

void ClimberSubsystem::InitDefaultCommand() {
	leftTalon->Set(0);
	rightTalon->Set(0);
}

void ClimberSubsystem::RunLeftTalon(float speed) {
	leftTalon->Set(speed);
}

void ClimberSubsystem::RunRightTalon(float speed) {
	rightTalon->Set(speed);
}
