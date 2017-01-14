#include "GearSubsystem.h"

#include "../RobotMap.h"

GearSubsystem::GearSubsystem() : Subsystem("GearSubsystem") {
	gearLoaderServo = RobotMap::gearSubsystemLoaderServo;
}

void GearSubsystem::InitDefaultCommand() {

}

void  GearSubsystem::SetAngleGearLoaderServos(float inputAngle)
{
	gearLoaderServo->SetAngle(inputAngle);
}
