#ifndef ClimberSubsystem_H
#define ClimberSubsystem_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>


class ClimberSubsystem : public Subsystem {
private:
	std::shared_ptr<CANTalon> leftTalon;
	std::shared_ptr<CANTalon> rightTalon;
public:
	ClimberSubsystem();
	void InitDefaultCommand();
	void RunLeftTalon(float speed);
	void RunRightTalon(float speed);
};

#endif
