#include "GearAlignCenter.h"

#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/FlapperSolenoid.h"
#include "../Gears/PusherSolenoid.h"
#include "../Autonomous/DoNothingAuto.h"

GearAlignCenter::GearAlignCenter() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, .7, 0));
	AddSequential(new AlignCenter(0));
	AddSequential(new FlapperSolenoid(1, 0));
	AddSequential(new DoNothingAuto(.25));
	AddSequential(new PusherSolenoid(1, 0));
	AddSequential(new DoNothingAuto(.5));
	AddSequential(new FlapperSolenoid(1, 1));
	AddSequential(new PusherSolenoid(1, 1));
}
