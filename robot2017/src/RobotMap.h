#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "TigerDrive/TigerDrive.h"
#include "CANTalon.h"

class RobotMap {
public:
	static void init();

	static std::shared_ptr<CANTalon> driveBaseSubsystemFrontLeftTalon;
	static std::shared_ptr<CANTalon> driveBaseSubsystemFrontRightTalon;
	static std::shared_ptr<CANTalon> driveBaseSubsystemBackLeftTalon;
	static std::shared_ptr<CANTalon> driveBaseSubsystemBackRightTalon;
	static std::shared_ptr<RobotDrive> driveBaseSubsystemRobotDrive;

	static std::shared_ptr<DoubleSolenoid> gearSubsystemFlapperSolenoid;
	static std::shared_ptr<DoubleSolenoid> gearSubsystemPusherSolenoid;
	static std::shared_ptr<DoubleSolenoid> gearSubsystemChuteSolenoid;

	static std::shared_ptr<CANTalon> shooterSubsystemFlywheelTalon;
	static std::shared_ptr<CANTalon> shooterSubsystemLoaderTalon;
	static std::shared_ptr<Servo> shooterSubsystemLoaderServo;

	static std::shared_ptr<CANTalon> climberSubsystemLeftTalon;
	static std::shared_ptr<CANTalon> climberSubsystemRightTalon;

	static std::shared_ptr<DigitalInput> gearSubsystemPressurePlate;

	static std::shared_ptr<PowerDistributionPanel> pdp;

	static std::shared_ptr<AHRS> robotIMU;
	static std::shared_ptr<TigerDrive> tigerDrive;
	static std::shared_ptr<SerialPort> arduino;
};
#endif
