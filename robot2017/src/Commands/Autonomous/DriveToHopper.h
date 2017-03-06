#ifndef DriveHopper_H
#define DriveHopper_H

#include <Commands/CommandGroup.h>
#include "../../Robot.h"

class DriveToHopper : public CommandGroup {
public:
	DriveToHopper(std::string lrc);
};

#endif
