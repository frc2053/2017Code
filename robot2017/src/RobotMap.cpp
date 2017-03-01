#include "RobotMap.h"

std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemFrontLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemFrontRightTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemBackLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemBackRightTalon;
std::shared_ptr<frc::RobotDrive> RobotMap::driveBaseSubsystemRobotDrive;

std::shared_ptr<frc::DoubleSolenoid> RobotMap::gearSubsystemFlapperSolenoid;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::gearSubsystemPusherSolenoid;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::gearSubsystemChuteSolenoid;

std::shared_ptr<frc::DigitalInput> RobotMap::gearSubsystemPressurePlate;

std::shared_ptr<CANTalon> RobotMap::shooterSubsystemFlywheelTalon;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemLoaderTalon;
std::shared_ptr<frc::Servo> RobotMap::shooterSubsystemLoaderServo;

std::shared_ptr<CANTalon> RobotMap::climberSubsystemLeftTalon;
std::shared_ptr<CANTalon> RobotMap::climberSubsystemRightTalon;

std::shared_ptr<frc::PowerDistributionPanel> RobotMap::pdp;

std::shared_ptr<AHRS> RobotMap::robotIMU;
std::shared_ptr<TigerDrive> RobotMap::tigerDrive;
std::shared_ptr<frc::SerialPort> RobotMap::arduino;

void RobotMap::init() {
    driveBaseSubsystemFrontLeftTalon.reset(new CANTalon(2));
    driveBaseSubsystemFrontRightTalon.reset(new CANTalon(8));
    driveBaseSubsystemBackLeftTalon.reset(new CANTalon(12));
    driveBaseSubsystemBackRightTalon.reset(new CANTalon(3));
    driveBaseSubsystemRobotDrive.reset(new frc::RobotDrive(driveBaseSubsystemFrontLeftTalon, driveBaseSubsystemBackLeftTalon, driveBaseSubsystemFrontRightTalon, driveBaseSubsystemBackRightTalon));

    driveBaseSubsystemRobotDrive->SetSafetyEnabled(false);
    driveBaseSubsystemRobotDrive->SetExpiration(0.1);
    driveBaseSubsystemRobotDrive->SetSensitivity(0.5);
    driveBaseSubsystemRobotDrive->SetMaxOutput(1.0);

    driveBaseSubsystemRobotDrive->SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);
    driveBaseSubsystemRobotDrive->SetInvertedMotor(frc::RobotDrive::kRearRightMotor, true);

    shooterSubsystemFlywheelTalon.reset(new CANTalon(9));
    shooterSubsystemLoaderTalon.reset(new CANTalon(5));
    shooterSubsystemLoaderServo.reset(new frc::Servo(1));

    shooterSubsystemFlywheelTalon->SetControlMode(CANTalon::kSpeed);
    //shooterSubsystemFlywheelTalon->Se
    shooterSubsystemFlywheelTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    shooterSubsystemFlywheelTalon->SetF(0.03330078125); //.0299707
    shooterSubsystemFlywheelTalon->SetP(0);
    shooterSubsystemFlywheelTalon->SetI(0);
    shooterSubsystemFlywheelTalon->SetD(0);

    shooterSubsystemLoaderTalon->SetControlMode(CANTalon::kSpeed);
    shooterSubsystemLoaderTalon->SetInverted(true);
    shooterSubsystemLoaderTalon->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    shooterSubsystemLoaderTalon->SetF(0.03330078125);
    shooterSubsystemLoaderTalon->SetP(0);
    shooterSubsystemLoaderTalon->SetI(0);
    shooterSubsystemLoaderTalon->SetD(0);

    gearSubsystemFlapperSolenoid.reset(new frc::DoubleSolenoid(3, 4)); //changed back to original robot
    gearSubsystemPusherSolenoid.reset(new frc::DoubleSolenoid(2, 5));
    gearSubsystemChuteSolenoid.reset(new frc::DoubleSolenoid(1, 6));
    gearSubsystemPressurePlate.reset(new frc::DigitalInput(0));

    climberSubsystemLeftTalon.reset(new CANTalon(7));
    climberSubsystemRightTalon.reset(new CANTalon(4));

    pdp.reset(new frc::PowerDistributionPanel());

    robotIMU.reset(new AHRS(frc::SPI::Port::kMXP));
    tigerDrive.reset(new TigerDrive(robotIMU.get()));
    arduino.reset(new frc::SerialPort(9600, frc::SerialPort::Port::kUSB, 8, frc::SerialPort::Parity::kParity_None, frc::SerialPort::StopBits::kStopBits_One));
}
