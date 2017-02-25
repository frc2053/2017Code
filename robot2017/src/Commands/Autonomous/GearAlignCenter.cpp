#include "GearAlignCenter.h"

#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/PushGearGroup.h"
#include "../Gears/RetractGearGroup.h"
#include "../Autonomous/DoNothingAuto.h"
#include "DriveToBoilerShootCenter.h"

GearAlignCenter::GearAlignCenter() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, 1.1, 0)); //drive forward
	//AddSequential(new AlignCenter(0)); //align
	//AddSequential(new DriveCommandAuto(0, -.5, 0, .8, 0)); //drive forward
	AddSequential(new DoNothingAuto(.25)); //wait
	AddSequential(new PushGearGroup());
	AddSequential(new DoNothingAuto(.5)); //wait
	AddSequential(new RetractGearGroup());
	AddSequential(new DriveCommandAuto(0, .5, 0, .5, 0)); //drive backwards
	std::cout << "FINISHED GEAR ALIGN CENTER" << std::endl;
	if(Robot::doBoiler) {
		std::cout << "MADE IT TO DO BOILER" << std::endl;

		AddSequential(new DriveToBoilerShootCenter()); //go to boiler
		std::cout << "FINISHED WITH DO BOILER" << std::endl;

	}
}
