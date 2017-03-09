#ifndef ShooterSubsystem_H
#define ShooterSubsystem_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include <WPILib.h>


class ShooterSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> flywheelTalon;
	std::shared_ptr<CANTalon> loaderTalon;
	std::shared_ptr<Servo> loaderServo;
	std::shared_ptr<Servo> hopperServo;
public:

	ShooterSubsystem();
	void InitDefaultCommand();
	void RunShooterMotor(float rpm);
	void RunLoaderMotor(float rpm);
	void SetServoAngle(float angle);
	void SetHopperServoAngle(float angle);
};

#endif
