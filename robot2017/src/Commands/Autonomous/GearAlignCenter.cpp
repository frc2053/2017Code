#include "GearAlignCenter.h"

#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/PushGearGroup.h"
#include "../Gears/RetractGearGroup.h"
#include "../Autonomous/DoNothingAuto.h"
#include "DriveToBoilerShootCenter.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"
#include "../Shooter/ShooterGroup.h"
#include "../Shooter/ShooterEndGroup.h"

GearAlignCenter::GearAlignCenter() {

	AddSequential(new PrintCommand("Starting Gear Align Center"));

	AddSequential(new DriveCommandAuto(0, -.5, 0, 1.3, 0)); //drive forward
	AddSequential(new DoNothingAuto(.35)); //wait
	AddSequential(new PushGearGroup());
	AddSequential(new DoNothingAuto(.35)); //wait
	AddSequential(new RetractGearGroup());
	AddSequential(new DriveCommandAuto(0, .5, 0, .5, 0)); //drive backwards

	AddSequential(new PrintCommand("Finished Gear Align Center"));


	if(Robot::doBoiler) {

		AddSequential(new PrintCommand("Calling Boiler From Center"));

		AddSequential(new DriveToBoilerShootCenter("center")); //go to boiler

		AddSequential(new PrintCommand("Finished Boiler From Center"));

	}
}
