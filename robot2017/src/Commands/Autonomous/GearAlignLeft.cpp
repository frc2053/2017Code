#include "GearAlignLeft.h"
#include "../Drive/AlignCenter.h"
#include "DriveCommandAuto.h"
#include "../Gears/FlapperSolenoid.h"
#include "../Gears/PusherSolenoid.h"
#include "../Autonomous/DoNothingAuto.h"
#include "DriveToBoilerClose.h"
#include "DriveToBoilerShootCenter.h"

GearAlignLeft::GearAlignLeft() {
	AddSequential(new DriveCommandAuto(0, -.5, 0, .7, 0));
	AddSequential(new AlignCenter(60));
	AddSequential(new DriveCommandAuto(0, -.5, 0, .5, 60));
	AddSequential(new FlapperSolenoid(1, 0));
	AddSequential(new DoNothingAuto(.25));
	AddSequential(new PusherSolenoid(1, 0));
	AddSequential(new DoNothingAuto(.5));
	AddSequential(new FlapperSolenoid(1, 1));
	AddSequential(new PusherSolenoid(1, 1));
	if(Robot::doBoiler) {
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
			AddSequential(new DriveToBoilerShootCenter());
		}
		if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
			AddSequential(new DriveCommandAuto(0, .5, 0, .5, 60)); // drive backwards
			AddSequential(new DriveCommandAuto(.5, 0, 0, 1, 0)); //drive right
			AddSequential(new DriveToBoilerShootCenter()); //align and shoot
		}
	}
}
