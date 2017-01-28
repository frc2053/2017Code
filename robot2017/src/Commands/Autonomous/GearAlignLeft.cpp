#include "GearAlignLeft.h"
#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Autonomous/DoNothingAuto.h"
#include "DriveToBoilerClose.h"
#include "DriveToBoilerShootCenter.h"
#include "../Gears/PushGearGroup.h"
#include "../Gears/RetractGearGroup.h"

GearAlignLeft::GearAlignLeft() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, .7, 0)); //drive forward
	AddSequential(new AlignCenter(60)); //align with the goal
	AddSequential(new DriveCommandAuto(0, -.5, 0, .5, 60)); //drive forward onto airship
	AddSequential(new PushGearGroup());
	AddSequential(new DoNothingAuto(.5)); //wait
	AddSequential(new RetractGearGroup());
	if(Robot::doBoiler) { //if we do boiler
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
			AddSequential(new DriveToBoilerShootCenter()); //if on blue we go to center
		}
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
			AddSequential(new DriveCommandAuto(0, .5, 0, .5, 60)); // drive backwards
			AddSequential(new DriveCommandAuto(.5, 0, 0, 1, 0)); //drive right
			AddSequential(new DriveToBoilerShootCenter()); //align and shoot
		}
	}
}
