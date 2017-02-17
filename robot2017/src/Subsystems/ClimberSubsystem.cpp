#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem") {
	leftTalon = RobotMap::climberSubsystemLeftTalon;
	rightTalon = RobotMap::climberSubsystemRightTalon;
}

void ClimberSubsystem::InitDefaultCommand() {
	//should have the left and right talon set
}

void ClimberSubsystem::RunLeftTalon(float speed) {
	leftTalon->Set(speed);
}

void ClimberSubsystem::RunRightTalon(float speed) {
	rightTalon->Set(speed);
}
