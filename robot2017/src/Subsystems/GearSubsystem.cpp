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
	flapperSolenoid->Set(frc::DoubleSolenoid::kForward);
}

void GearSubsystem::SetFlapperDown() {
	flapperSolenoid->Set(frc::DoubleSolenoid::kReverse);
}

void GearSubsystem::SetPusherForward() {
	pusherSolenoid->Set(frc::DoubleSolenoid::kForward);
}

void GearSubsystem::SetPusherBack() {
	pusherSolenoid->Set(frc::DoubleSolenoid::kReverse);
}

void GearSubsystem::SetChuteForward() {
	chuteSolenoid->Set(frc::DoubleSolenoid::kForward);
}

void GearSubsystem::SetChuteBack() {
	chuteSolenoid->Set(frc::DoubleSolenoid::kReverse);
}

frc::DoubleSolenoid::Value GearSubsystem::GetFlapperState() {
	return flapperSolenoid->Get();
}

frc::DoubleSolenoid::Value GearSubsystem::GetPusherState() {
	return pusherSolenoid->Get();
}

frc::DoubleSolenoid::Value GearSubsystem::GetChuteState() {
	return chuteSolenoid->Get();
}
