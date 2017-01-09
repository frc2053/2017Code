#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "AHRS.h"

class RobotMap {
public:
	static void init();


	static std::shared_ptr<AHRS> robotIMU;
};
#endif
