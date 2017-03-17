#ifndef BLUE_DriveToBoiler_H
#define BLUE_DriveToBoiler_H

#include <Commands/CommandGroup.h>
#include "../../Robot.h"

class BLUE_DriveToBoiler : public CommandGroup {
public:
	BLUE_DriveToBoiler(std::string pos);
};

#endif
