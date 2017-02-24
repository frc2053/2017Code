#ifndef ShooterSubsystem_H
#define ShooterSubsystem_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>


class ShooterSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<CANTalon> flywheelTalon;
	std::shared_ptr<CANTalon> loaderTalon;
	std::shared_ptr<CANTalon> turretTalon;
public:

	ShooterSubsystem();
	void InitDefaultCommand();
	void RunShooterMotor(float rpm);
	void RunLoaderMotor(float rpm);
	void RunTurretMotor(float pos);
	double GetAngleOfTurret();
};

#endif
