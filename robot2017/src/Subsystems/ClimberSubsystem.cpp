#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem") {
	leftTalon = RobotMap::climberSubsystemLeftTalon;
	rightTalon = RobotMap::climberSubsystemRightTalon;
}

void ClimberSubsystem::InitDefaultCommand() {

}

void ClimberSubsystem::RunLeftTalon(float speed) {
	leftTalon->Set(speed);
}

void ClimberSubsystem::RunRightTalon(float speed) {
	rightTalon->Set(speed);
}
