#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "RobotMap.h"

#include "Subsystems/DrivebaseSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Subsystems/GearSubsystem.h"
#include "Subsystems/ClimberSubsystem.h"
#include "Subsystems/LedSubsystem.h"
#include "OI.h"

class Robot : public IterativeRobot {
public:
    static std::shared_ptr<DrivebaseSubsystem> drivebaseSubsystem;
    static std::shared_ptr<ShooterSubsystem> shooterSubsystem;
    static std::shared_ptr<GearSubsystem> gearSubsystem;
    static std::shared_ptr<ClimberSubsystem> climberSubsystem;
    static std::shared_ptr<LedSubsystem> ledSubsystem;
    static std::shared_ptr<OI> oi;

    static std::shared_ptr<NetworkTable> visionTable;

	static frc::DriverStation::Alliance currentAlliance;

	static std::shared_ptr<DigitalInput> pressureplate;

	static bool doBoiler;

    virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
private:
	frc::SendableChooser<frc::Command*> autoChooser;
	std::unique_ptr<frc::Command> selectedMode;
};
#endif
