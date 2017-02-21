#include "GearSubsystem.h"

#include "../RobotMap.h"

GearSubsystem::GearSubsystem() : Subsystem("GearSubsystem") {
	flapperSolenoid = RobotMap::gearSubsystemFlapperSolenoid;
	pusherSolenoid = RobotMap::gearSubsystemPusherSolenoid;
	chuteSolenoid = RobotMap::gearSubsystemChuteSolenoid;
	pressurePlate = RobotMap::gearSubsystemPressurePlate;
}

void GearSubsystem::InitDefaultCommand() {

}

void GearSubsystem::SetFlapperUp() {
	flapperSolenoid->Set(frc::DoubleSolenoid::kReverse);
}

void GearSubsystem::SetFlapperDown() {
	flapperSolenoid->Set(frc::DoubleSolenoid::kForward);
}

void GearSubsystem::SetPusherForward() {
	pusherSolenoid->Set(frc::DoubleSolenoid::kReverse);
}

void GearSubsystem::SetPusherBack() {
	pusherSolenoid->Set(frc::DoubleSolenoid::kForward);
}

void GearSubsystem::SetChuteForward() {
	chuteSolenoid->Set(frc::DoubleSolenoid::kReverse);
}

void GearSubsystem::SetChuteBack() {
	chuteSolenoid->Set(frc::DoubleSolenoid::kForward);
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

bool GearSubsystem::GetPressurePlateState() {
	return pressurePlate->Get();
}
