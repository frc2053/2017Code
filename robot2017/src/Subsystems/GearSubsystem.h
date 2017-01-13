#ifndef GearSubsystem_H
#define GearSubsystem_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class GearSubsystem : public Subsystem {
private:
	std::shared_ptr<Servo> gearLoaderServo;
public:
	GearSubsystem();
	void InitDefaultCommand();

	void SetAngleGearLoaderServos(float inputAngle);
};

#endif
