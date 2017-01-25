#include "GearAlignRight.h"

#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/FlapperSolenoid.h"
#include "../Gears/PusherSolenoid.h"
#include "../Autonomous/DoNothingAuto.h"

GearAlignRight::GearAlignRight() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, .7, 0));
	AddSequential(new AlignCenter(-60));
	AddSequential(new DriveCommandAuto(0, -.5, 0, .5, -60));
	AddSequential(new FlapperSolenoid(1, 0));
	AddSequential(new DoNothingAuto(.25));
	AddSequential(new PusherSolenoid(1, 0));
	AddSequential(new DoNothingAuto(.5));
	AddSequential(new FlapperSolenoid(1, 1));
	AddSequential(new PusherSolenoid(1, 1));
}
