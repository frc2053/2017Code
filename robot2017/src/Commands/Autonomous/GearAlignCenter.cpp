#include "GearAlignCenter.h"

#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/FlapperSolenoid.h"
#include "../Gears/PusherSolenoid.h"
#include "../Autonomous/DoNothingAuto.h"
#include "DriveToBoilerShootCenter.h"

GearAlignCenter::GearAlignCenter() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, .7, 0)); //drive forward
	AddSequential(new AlignCenter(0)); //align
	AddSequential(new FlapperSolenoid(1, 0)); //retract flapper
	AddSequential(new DoNothingAuto(.25)); //wait
	AddSequential(new PusherSolenoid(1, 0)); //push gear onto peg
	AddSequential(new DoNothingAuto(.5)); //wait
	AddSequential(new FlapperSolenoid(1, 1)); //retract gear pusher
	AddSequential(new PusherSolenoid(1, 1)); //extend gear flapper
	AddSequential(new DriveCommandAuto(0, .5, 0, .5, 0)); //drive backwards
	if(Robot::doBoiler) {
		AddSequential(new DriveToBoilerShootCenter()); //go to boiler
	}
}
