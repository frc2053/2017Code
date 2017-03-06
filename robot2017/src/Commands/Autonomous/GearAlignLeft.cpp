#include "GearAlignLeft.h"
#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Autonomous/DoNothingAuto.h"
#include "DriveToBoilerShootCenter.h"
#include "../Gears/RetractGearGroup.h"
#include "../Gears/PushGearGroup.h"


GearAlignLeft::GearAlignLeft() {
	AddSequential(new PrintCommand("Starting Gear Align Left"));

	AddSequential(new DriveCommandAuto(0, -.5, 0, .85, 0));  //drive forward
	//AddSequential(new AlignCenter(-60)); //align with gear
	AddSequential(new DriveCommandAuto(.25, -.25, 0, 1.6, 60)); //drive onto airship

	//AddSequential(new DoNothingAuto(.25)); //wait
	AddSequential(new PushGearGroup());
	AddSequential(new DoNothingAuto(.25)); //wait
	AddSequential(new RetractGearGroup());

	AddSequential(new DriveCommandAuto(-.25, .25, 0, .6, 60)); //backs up

	AddSequential(new PrintCommand("Finished Gear Align Left"));

	if(Robot::doBoiler) {
		AddSequential(new PrintCommand("Calling Boiler From Left"));
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
			AddSequential(new DriveToBoilerShootCenter("leftblue")); //go to boiler
		}

		if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
			AddSequential(new DriveToBoilerShootCenter("leftred")); //go to boiler
		}
		AddSequential(new PrintCommand("Finished Boiler From Left"));
	}
}
