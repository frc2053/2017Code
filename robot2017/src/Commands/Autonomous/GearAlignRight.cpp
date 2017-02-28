#include "GearAlignRight.h"

#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/RetractGearGroup.h"
#include "../Gears/PushGearGroup.h"
#include "DoNothingAuto.h"
#include "DriveToBoilerShootCenter.h"
#include "DriveToBoilerClose.h"

GearAlignRight::GearAlignRight() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, .7, 0));  //drive forward needs to drive farther
//	AddSequential(new AlignCenter(-60)); //align with gear
	AddSequential(new DriveCommandAuto(-.5, -.5, 0, .3, -60)); //drive onto airship
	AddSequential(new DoNothingAuto(.25)); //wait
	AddSequential(new PushGearGroup());
	AddSequential(new DoNothingAuto(.5)); //wait
	AddSequential(new RetractGearGroup());
	if(Robot::doBoiler) { //if we do boiler
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
			AddSequential(new DriveCommandAuto(0, .5, 0, .5, -60)); //drive backwards
			AddSequential(new DriveCommandAuto(-.5, 0, 0, 1, 0)); //drive left
			AddSequential(new DriveToBoilerShootCenter()); //align and shoot
		}
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
			AddSequential(new DriveToBoilerClose()); //drive to boiler
		}
	}
}
