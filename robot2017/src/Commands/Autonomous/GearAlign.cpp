#include "GearAlign.h"
#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"

GearAlign::GearAlign() {
	AddSequential(new AlignCenter());
	AddSequential(new DriveCommandAuto(0, .5, 0, .25, 0));
}
