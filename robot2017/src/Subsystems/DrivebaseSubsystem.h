#ifndef DRIVEBASESUBSYSTEM_H
#define DRIVEBASESUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivebaseSubsystem: public Subsystem {
private:
public:
	DrivebaseSubsystem();
	void InitDefaultCommand();
};

#endif
