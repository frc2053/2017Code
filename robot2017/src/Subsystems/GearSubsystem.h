#ifndef GearSubsystem_H
#define GearSubsystem_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class GearSubsystem : public Subsystem {
private:
	std::shared_ptr<DoubleSolenoid> flapperSolenoid;
	std::shared_ptr<DoubleSolenoid> pusherSolenoid;
	std::shared_ptr<DoubleSolenoid> chuteSolenoid;
	std::shared_ptr<DigitalInput> pressurePlate;
public:
	GearSubsystem();
	void InitDefaultCommand();

	void SetFlapperUp();
	void SetFlapperDown();

	void SetPusherForward();
	void SetPusherBack();

	void SetChuteForward();
	void SetChuteBack();

	DoubleSolenoid::Value GetFlapperState();
	DoubleSolenoid::Value GetPusherState();
	DoubleSolenoid::Value GetChuteState();
	bool GetPressurePlateState();
};

#endif
