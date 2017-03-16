#include "GearAlignRight.h"
#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Autonomous/DoNothingAuto.h"
#include "DriveToBoilerShootCenter.h"
#include "../Gears/RetractGearGroup.h"
#include "../Gears/PushGearGroup.h"


GearAlignRight::GearAlignRight() {
	AddSequential(new PrintCommand("Starting Gear Align Right"));

	AddSequential(new DriveCommandAuto(0, -.5, 0, .95, 0));  //drive forward
	AddSequential(new DriveCommandAuto(-.25, -.43, 0, .4, -60)); //drive towards airship
	//if(Robot::doCamera)
	if(SmartDashboard::GetBoolean("Do Camera", true))
	{
		AddSequential(new PrintCommand("TRIED TO DO GEAR ALIGN CENTER -60!"));
		AddSequential(new AlignCenter(-60)); //align with gear
	}
	if(Robot::doCamera) {
		AddSequential(new AlignCenter(-60)); //align with gear
	}
	AddSequential(new DriveCommandAuto(-.25, -.43, 0, 1.5, -60)); //drive onto airship

	AddSequential(new DoNothingAuto(.25)); //wait
	AddSequential(new PushGearGroup());
	AddSequential(new DoNothingAuto(.25)); //wait
	AddSequential(new RetractGearGroup());

	AddSequential(new DriveCommandAuto(.25, .43, 0, .6, -60)); //backs up

	AddSequential(new PrintCommand("Finished Gear Align Right"));

	if(Robot::doBoiler) {
		AddSequential(new PrintCommand("Calling Boiler From Right"));

		AddSequential(new DriveToBoilerShootCenter("rightblue")); //go to boiler

		AddSequential(new PrintCommand("Finished Boiler From Right"));
	}
}
