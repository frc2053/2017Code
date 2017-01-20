#include "GearSubsystem.h"

#include "../RobotMap.h"

GearSubsystem::GearSubsystem() : Subsystem("GearSubsystem") {
	flapperSolenoid = RobotMap::gearSubsystemFlapperSolenoid;
	pusherSolenoid = RobotMap::gearSubsystemPusherSolenoid;
}

void GearSubsystem::InitDefaultCommand() {

}

void GearSubsystem::SetFlapperUp() {
	flapperSolenoid->Set(DoubleSolenoid::kForward);
}

void GearSubsystem::SetFlapperDown() {
	flapperSolenoid->Set(DoubleSolenoid::kReverse);
}

void GearSubsystem::SetPusherForward() {
	pusherSolenoid->Set(DoubleSolenoid::kForward);
}

void GearSubsystem::SetPusherBack() {
	pusherSolenoid->Set(DoubleSolenoid::kReverse);
}
