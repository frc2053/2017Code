#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Drive/ZeroYaw.h"


OI::OI() {
	driverJoystick.reset(new Joystick(0));

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
