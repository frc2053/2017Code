#include "GearAlignCenter.h"

#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/PushGearGroup.h"
#include "../Gears/RetractGearGroup.h"
#include "../Autonomous/DoNothingAuto.h"
#include "DriveToBoilerShootCenter.h"

GearAlignCenter::GearAlignCenter() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, .7, 0)); //drive forward
	AddSequential(new AlignCenter(0)); //align
	AddSequential(new PushGearGroup());
	AddSequential(new DoNothingAuto(.5)); //wait
	AddSequential(new RetractGearGroup());
	AddSequential(new DriveCommandAuto(0, .5, 0, .5, 0)); //drive backwards
	if(Robot::doBoiler) {
		AddSequential(new DriveToBoilerShootCenter()); //go to boiler
	}
}
