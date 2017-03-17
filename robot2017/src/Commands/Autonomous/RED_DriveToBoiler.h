#ifndef RED_DriveToBoiler_H
#define RED_DriveToBoiler_H

#include <Commands/CommandGroup.h>
#include "../../Robot.h"


class RED_DriveToBoiler : public CommandGroup {
public:
	RED_DriveToBoiler(std::string pos);
};

#endif
