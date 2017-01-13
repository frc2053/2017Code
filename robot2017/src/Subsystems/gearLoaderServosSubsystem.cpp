#include "gearLoaderServosSubsystem.h"
#include "../RobotMap.h"

gearLoaderServosSubsystem::gearLoaderServosSubsystem() : Subsystem("GearSubsystem") {
	gearLoaderServo = RobotMap::gearLoaderServo;
}

void gearLoaderServosSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void  gearLoaderServosSubsystem::SetAngleGearLoaderServos(float inputAngle)
{
	gearLoaderServo->SetAngle(inputAngle);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
