#ifndef ShooterSubsystem_H
#define ShooterSubsystem_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

class ShooterSubsystem : public Subsystem {
private:
	std::shared_ptr<CANTalon> flywheelTalon;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void RunMotor(float rpm);
};

#endif
