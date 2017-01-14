#ifndef ShooterSubsystem_H
#define ShooterSubsystem_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>


class ShooterSubsystem : public Subsystem {
private:
	std::shared_ptr<CANTalon> flywheelTalon;
	std::shared_ptr<CANTalon> loaderTalon;
public:

	ShooterSubsystem();
	void InitDefaultCommand();
	void RunShooterMotor(float rpm);
	void RunLoaderMotor(float speed);
};

#endif
