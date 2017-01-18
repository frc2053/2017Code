#include "RobotMap.h"

std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemFrontLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemFrontRightTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemBackLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemBackRightTalon;
std::shared_ptr<frc::RobotDrive> RobotMap::driveBaseSubsystemRobotDrive;
std::shared_ptr<frc::Servo> RobotMap::gearSubsystemLoaderServo;

std::shared_ptr<CANTalon> RobotMap::shooterSubsystemFlywheelTalon;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemLoaderTalon;

std::shared_ptr<frc::PowerDistributionPanel> RobotMap::pdp;

std::shared_ptr<AHRS> RobotMap::robotIMU;
std::shared_ptr<TigerDrive> RobotMap::tigerDrive;

void RobotMap::init() {
    driveBaseSubsystemFrontLeftTalon.reset(new CANTalon(9));
    driveBaseSubsystemFrontRightTalon.reset(new CANTalon(8));
    driveBaseSubsystemBackLeftTalon.reset(new CANTalon(4));
    driveBaseSubsystemBackRightTalon.reset(new CANTalon(2));
    driveBaseSubsystemRobotDrive.reset(new frc::RobotDrive(driveBaseSubsystemFrontLeftTalon, driveBaseSubsystemBackLeftTalon, driveBaseSubsystemFrontRightTalon, driveBaseSubsystemBackRightTalon));

    driveBaseSubsystemRobotDrive->SetSafetyEnabled(false);
    driveBaseSubsystemRobotDrive->SetExpiration(0.1);
    driveBaseSubsystemRobotDrive->SetSensitivity(0.5);
    driveBaseSubsystemRobotDrive->SetMaxOutput(1.0);

    driveBaseSubsystemRobotDrive->SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);
    driveBaseSubsystemRobotDrive->SetInvertedMotor(frc::RobotDrive::kRearRightMotor, true);

    shooterSubsystemFlywheelTalon.reset(new CANTalon(3));

    //temporary talon id
    shooterSubsystemLoaderTalon.reset(new CANTalon(5));



    shooterSubsystemFlywheelTalon->SetControlMode(CANTalon::kSpeed);
    shooterSubsystemFlywheelTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    shooterSubsystemFlywheelTalon->SetF(.0299707);
    shooterSubsystemFlywheelTalon->SetD(0);
    shooterSubsystemFlywheelTalon->SetI(0);
    shooterSubsystemFlywheelTalon->SetD(0);


    gearSubsystemLoaderServo.reset(new frc::Servo(0));


    pdp.reset(new frc::PowerDistributionPanel());

    robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));
    tigerDrive.reset(new TigerDrive(robotIMU.get()));
}
