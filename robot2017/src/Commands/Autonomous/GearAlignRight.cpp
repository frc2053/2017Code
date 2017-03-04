#include "GearAlignRight.h"

#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/RetractGearGroup.h"
#include "../Gears/PushGearGroup.h"
#include "DoNothingAuto.h"
#include "DriveToBoilerShootCenter.h"
#include "DriveToBoilerClose.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"

GearAlignRight::GearAlignRight() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, .9, 0));  //drive forward needs to drive farther
	//AddSequential(new AlignCenter(-60)); //align with gear
	AddSequential(new DriveCommandAuto(-.25, -.25, 0, 1.5, -60)); //drive onto airship
	AddSequential(new DoNothingAuto(.25)); //wait
	AddSequential(new PushGearGroup());
	AddSequential(new DoNothingAuto(.5)); //wait
	AddSequential(new RetractGearGroup());
	AddSequential(new DriveCommandAuto(.25, .25, 0, .6, -60)); //drive onto airship

	AddSequential(new DriveCommandAuto(-.5, .5, 0, 1.6, -135)); //drive onto airship

	AddSequential(new DriveCommandAuto(-.75, 0, 0, 2, -90)); //drive onto airship

	AddSequential(new ShooterWheel(SmartDashboard::GetNumber("Shooter RPM", 4000), 5)); //fires
	AddSequential(new DoNothingAuto(.5));  //lets the shooter get to speed
	AddSequential(new LoaderWheel(SmartDashboard::GetNumber("Loader RPM", 3000), 2)); //loads

	/*if(Robot::doBoiler) { //if we do boiler
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
			AddSequential(new DriveCommandAuto(0, .5, 0, .5, -60)); //drive backwards
			AddSequential(new DriveCommandAuto(-.5, 0, 0, 1, 0)); //drive left
			AddSequential(new DriveToBoilerShootCenter()); //align and shoot
		}
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
			AddSequential(new DriveToBoilerClose()); //drive to boiler
		}*/


	}

