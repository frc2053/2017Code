#ifndef DriveToBoiler_H
#define DriveToBoiler_H

#include <Commands/CommandGroup.h>
#include "../../Robot.h"

class DriveToBoilerShootCenter : public CommandGroup {
public:
	DriveToBoilerShootCenter(std::string rlc);
};

#endif
