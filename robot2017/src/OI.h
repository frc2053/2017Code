#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "Util/TigerTrigger/TigerLeftTrigger.h"
#include "Util/TigerTrigger/TigerRightTrigger.h"

class OI {
private:
	std::shared_ptr<Joystick> driverJoystick;
public:
	OI();

	std::shared_ptr<Joystick> GetDriverJoystick();

	double GetLeftXAxisDriver();
	double GetLeftYAxisDriver();
	double GetRightXAxisDriver();
	double GetRightYAxisDriver();
	bool GetAButtonDriver();
	bool GetBButtonDriver();
	bool GetXButtonDriver();
	bool GetYButtonDriver();
	bool GetLeftBumperDriver();
	bool GetRightBumperDriver();
	bool GetBackButtonDriver();
	bool GetStartButtonDriver();
	bool GetLeftStickButtonDriver();
	bool GetRightStickButtonDriver();

	float DeadBandJoystick(float axis);
};

#endif
