#ifndef GearSubsystem_H
#define GearSubsystem_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class GearSubsystem : public Subsystem {
private:
	std::shared_ptr<DoubleSolenoid> flapperSolenoid;
	std::shared_ptr<DoubleSolenoid> pusherSolenoid;
public:
	GearSubsystem();
	void InitDefaultCommand();

	void SetFlapperUp();
	void SetFlapperDown();

	void SetPusherForward();
	void SetPusherBack();
};

#endif
