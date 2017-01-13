#ifndef gearLoaderServosSubsystem_H
#define gearLoaderServosSubsystem_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class gearLoaderServosSubsystem : public Subsystem {
private:
	std::shared_ptr<Servo> gearLoaderServo;
public:
	void SetAngleGearLoaderServos(float inputAngle);

	gearLoaderServosSubsystem();
	void InitDefaultCommand();
};

#endif  // gearLoaderServosSubsystem_H
