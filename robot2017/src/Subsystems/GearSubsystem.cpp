#include "GearSubsystem.h"

#include "../RobotMap.h"

GearSubsystem::GearSubsystem() : Subsystem("GearSubsystem") {
	flapperSolenoid = RobotMap::gearSubsystemFlapperSolenoid;
	pusherSolenoid = RobotMap::gearSubsystemPusherSolenoid;
	chuteSolenoid = RobotMap::gearSubsystemChuteSolenoid;
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

void GearSubsystem::SetChuteForward() {
	chuteSolenoid->Set(DoubleSolenoid::kForward);
}

void GearSubsystem::SetChuteBack() {
	chuteSolenoid->Set(DoubleSolenoid::kReverse);
}

DoubleSolenoid::Value GearSubsystem::GetFlapperState() {
	return flapperSolenoid->Get();
}

DoubleSolenoid::Value GearSubsystem::GetPusherState() {
	return pusherSolenoid->Get();
}

DoubleSolenoid::Value GearSubsystem::GetChuteState() {
	return chuteSolenoid->Get();
}
