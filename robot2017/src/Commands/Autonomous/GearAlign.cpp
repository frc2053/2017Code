#include "GearAlign.h"
#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/FlapperSolenoid.h"
#include "../Gears/PusherSolenoid.h"
#include "../Autonomous/DoNothingAuto.h"

GearAlign::GearAlign() {
	AddSequential(new AlignCenter());
	AddSequential(new DriveCommandAuto(0, .5, 0, .25, 0));
	AddSequential(new FlapperSolenoid(1, 0));
	AddSequential(new PusherSolenoid(1, 0));
	AddSequential(new DoNothingAuto(1));
	AddSequential(new FlapperSolenoid(1, 1));
	AddSequential(new PusherSolenoid(1, 1));
}
