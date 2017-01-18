#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "RobotMap.h"

#include "Subsystems/DrivebaseSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"
#include "OI.h"
#include "Subsystems/GearSubsystem.h"

class Robot : public IterativeRobot {
public:
	static std::unique_ptr<OI> oi;
    static std::shared_ptr<DrivebaseSubsystem> drivebaseSubsystem;
    static std::shared_ptr<ShooterSubsystem> shooterSubsystem;
    static std::shared_ptr<GearSubsystem> gearSubsystem;

    static std::shared_ptr<NetworkTable> visionTable;


    virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
