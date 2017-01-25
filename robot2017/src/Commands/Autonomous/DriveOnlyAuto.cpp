#include "Autonomous/DriveOnlyAuto.h"
#include "DriveCommandAuto.h"

DriveOnlyAuto::DriveOnlyAuto() {
	AddSequential(new DriveCommandAuto(0, 1, 0, 1, 0));
}
