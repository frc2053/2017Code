#include "DrivebaseSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/DriveCommand.h"

DrivebaseSubsystem::DrivebaseSubsystem() : Subsystem("DrivebaseSubsystem") {

}

void DrivebaseSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new DriveCommand());
}
