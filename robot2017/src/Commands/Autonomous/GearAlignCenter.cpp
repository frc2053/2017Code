#include "GearAlignCenter.h"

#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/PushGearGroup.h"
#include "../Gears/RetractGearGroup.h"
#include "../Autonomous/DoNothingAuto.h"
#include "DriveToBoilerShootCenter.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"

GearAlignCenter::GearAlignCenter() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, 1.2, 0)); //drive forward
	//AddSequential(new AlignCenter(0)); //align
	//AddSequential(new DriveCommandAuto(0, -.5, 0, .8, 0)); //drive forward
	AddSequential(new DoNothingAuto(.25)); //wait
	AddSequential(new PushGearGroup());
	AddSequential(new DoNothingAuto(.5)); //wait
	AddSequential(new RetractGearGroup());
	AddSequential(new DriveCommandAuto(0, .5, 0, .5, 0)); //drive backwards
	AddSequential(new PrintCommand("FINISHED GEAR ALIGN CENTER"));
	if(Robot::doBoiler) {
		AddSequential(new PrintCommand("MADE IT TO DO BOILER"));
		AddSequential(new PrintCommand( "REACHED THE DRIVE TO BOILER SHOOT CENTER"));
		//AddSequential(new DriveCommandAuto(0, 0, 0, 1, -135));
		//AddSequential(new DoNothingAuto(1));
		AddSequential(new PrintCommand("FINISHED ROTATING"));
		AddSequential(new DriveCommandAuto(0.01, 0, 0, 1, -90));//TURNS 90
		AddSequential(new PrintCommand("FINISHED TURNING 90"));

		AddSequential(new DriveCommandAuto(-1, 0, 0, .25, -90));//DRIVE SIDEWAYS
		AddSequential(new PrintCommand("FINISHED GETTING TO THE DSBOIFS	"));


		/*AddSequential(new DriveCommandAuto(-.5, .5, 0, .25, -135));
		AddSequential(new PrintCommand("FINISHED BOILER 135 DRIVE COMMAND"));



		AddSequential(new ShooterWheel(SmartDashboard::GetNumber("Shooter RPM", 4000), 5)); //fires
		AddSequential(new DoNothingAuto(.5));  //lets the shooter get to speed
		AddSequential(new LoaderWheel(SmartDashboard::GetNumber("Loader RPM", 3000), 2)); //loads
		//AddSequential(new DoNothingAuto(1));
		AddSequential(new PrintCommand("END OF DRIVE COMMANDS"));
		//AddSequential(new DriveToBoilerShootCenter()); //go to boiler
		AddSequential(new PrintCommand("FINISHED WITH DO BOILER"));
		*/
	}
}
