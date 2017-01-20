#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Drive/ZeroYaw.h"
#include "Commands/Shooter/ShooterWheel.h"
#include "Commands/Shooter/LoaderWheel.h"
#include "Commands/Drive/AlignCenter.h"
#include "Commands/Climber/ClimbMotor.h"
#include "Commands/Gears/FlapperSolenoid.h"
#include "Commands/Gears/PusherSolenoid.h"

OI::OI() {
	driverJoystick.reset(new Joystick(0));
	operatorJoystick.reset(new Joystick(1));

	aButtonOperator.reset(new JoystickButton(operatorJoystick.get(), 1));
	bButtonOperator.reset(new JoystickButton(operatorJoystick.get(), 2));
	xButtonOperator.reset(new JoystickButton(operatorJoystick.get(), 3));
	yButtonOperator.reset(new JoystickButton(operatorJoystick.get(), 4));
	leftBumperOperator.reset(new JoystickButton(operatorJoystick.get(), 5));
	rightBumperOperator.reset(new JoystickButton(operatorJoystick.get(), 6));

	leftBumperDriver.reset(new JoystickButton(driverJoystick.get(), 5));

	leftBumperDriver->WhenPressed(new AlignCenter());

	aButtonOperator->WhenPressed(new ShooterWheel(5000, 0));
	aButtonOperator->WhenReleased(new ShooterWheel(0, 0));

	xButtonOperator->WhenPressed(new LoaderWheel(1, 0));
	xButtonOperator->WhenReleased(new LoaderWheel(0, 0));

	bButtonOperator->WhenPressed(new FlapperSolenoid(0, 0));

	yButtonOperator->WhenPressed(new PusherSolenoid(0, 0));

	leftBumperOperator->WhenPressed(new ClimbMotor(1, 0));
	leftBumperOperator->WhenPressed(new ClimbMotor(0, 0));

	rightBumperOperator->WhenPressed(new ClimbMotor(-1, 0));
	rightBumperOperator->WhenPressed(new ClimbMotor(0, 0));

	SmartDashboard::PutData("Zero Yaw", new ZeroYaw());

}

double OI::GetLeftXAxisDriver() {
	double joystickValue = OI::DeadBandJoystick(driverJoystick.get()->GetRawAxis(0));
	return joystickValue;
}

double OI::GetLeftYAxisDriver() {
	double joystickValue = OI::DeadBandJoystick(driverJoystick.get()->GetRawAxis(1));
	return joystickValue;
}

double OI::GetRightXAxisDriver() {
	double joystickValue = OI::DeadBandJoystick(driverJoystick.get()->GetRawAxis(4));
	return joystickValue;
}

double OI::GetRightYAxisDriver() {
	double joystickValue = OI::DeadBandJoystick(driverJoystick.get()->GetRawAxis(5));
	return joystickValue;
}

double OI::GetLeftXAxisOperator() {
	double joystickValue = OI::DeadBandJoystick(operatorJoystick.get()->GetRawAxis(0));
	return joystickValue;
}

double OI::GetLeftYAxisOperator() {
	double joystickValue = OI::DeadBandJoystick(operatorJoystick.get()->GetRawAxis(1));
	return joystickValue;
}

double OI::GetRightXAxisOperator() {
	double joystickValue = OI::DeadBandJoystick(operatorJoystick.get()->GetRawAxis(4));
	return joystickValue;
}

double OI::GetRightYAxisOperator() {
	double joystickValue = OI::DeadBandJoystick(operatorJoystick.get()->GetRawAxis(5));
	return joystickValue;
}

float OI::DeadBandJoystick(float axis) {
	if(axis > -0.20 && axis < 0.20)
	{
		axis = 0;
	}
	else
	{
		axis = axis * fabs(axis);
	}
	return axis;
}

bool OI::GetAButtonDriver() {
	return driverJoystick->GetRawButton(1);
}

bool OI::GetBButtonDriver() {
	return driverJoystick->GetRawButton(2);
}

bool OI::GetXButtonDriver() {
	return driverJoystick->GetRawButton(3);
}

bool OI::GetYButtonDriver() {
	return driverJoystick->GetRawButton(4);
}

bool OI::GetLeftBumperDriver() {
	return driverJoystick->GetRawButton(5);
}

bool OI::GetRightBumperDriver() {
	return driverJoystick->GetRawButton(6);
}

bool OI::GetBackButtonDriver() {
	return driverJoystick->GetRawButton(7);
}

bool OI::GetStartButtonDriver() {
	return driverJoystick->GetRawButton(8);
}

bool OI::GetLeftStickButtonDriver() {
	return driverJoystick->GetRawButton(9);
}

bool OI::GetRightStickButtonDriver() {
	return driverJoystick->GetRawButton(10);
}

bool OI::GetAButtonOperator() {
	return operatorJoystick->GetRawButton(1);
}

bool OI::GetBButtonOperator() {
	return operatorJoystick->GetRawButton(2);
}

bool OI::GetXButtonOperator() {
	return operatorJoystick->GetRawButton(3);
}

bool OI::GetYButtonOperator() {
	return operatorJoystick->GetRawButton(4);
}

bool OI::GetLeftBumperOperator() {
	return operatorJoystick->GetRawButton(5);
}

bool OI::GetRightBumperOperator() {
	return operatorJoystick->GetRawButton(6);
}

bool OI::GetBackButtonOperator() {
	return operatorJoystick->GetRawButton(7);
}

bool OI::GetStartButtonOperator() {
	return operatorJoystick->GetRawButton(8);
}

bool OI::GetLeftStickButtonOperator() {
	return operatorJoystick->GetRawButton(9);
}

bool OI::GetRightStickButtonOperator() {
	return operatorJoystick->GetRawButton(10);
}
