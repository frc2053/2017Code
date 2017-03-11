#include "DriveToHopper.h"

#include "DriveCommandAuto.h"
#include "../Drive/AlignCenter.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"
#include "../Autonomous/DoNothingAuto.h"
#include "../Shooter/LoaderServo.h"
#include "../Shooter/ShooterGroup.h"

#define BoilerShooterSpeed 4500
#define BoilerLoaderSpeed  3000

DriveToHopper::DriveToHopper(std::string lrc) {

	int rev = 1; //default - serves as multiplier for field side to side reversals, because field isnt symmetric red to blue
	std::string leftrightcenter = lrc;

	AddSequential(new PrintCommand("In Hopper Processing"));


	if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
		rev = 1; // tested auto on blue setup, this remains positive
	}


	if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
		rev = -1; // reverse some directions for red field setup
	}





	if((!leftrightcenter.compare("leftblue")) || (!leftrightcenter.compare("rightred"))) { //if (left and blue) or (right and red)

		AddSequential(new PrintCommand("Starting Hopper LeftBlue / RightRed"));

		AddSequential(new DriveCommandAuto(0, 0, 0, .7, 90)); //rotates to 90
		AddSequential(new DriveCommandAuto(rev*(-1), 0, 0, .8, 90)); //rotates to smash into hopper
		AddParallel(new ShooterWheel(BoilerShooterSpeed, 12)); //spins up shooter wheels and runs for 12 seconds or until auto done
		AddSequential(new DriveCommandAuto(0, 0, 0, 1, 180)); //rotates to 180
		AddSequential(new DriveCommandAuto(rev*(-1), 0, 0, .5, 180)); //rotates to 180
		//AddSequential(new DriveCommandAuto(rev*(-.5), 0, 0, 4, 180)); //smash wildly into side wall hopper activator causing an avalanche of balls

		AddSequential(new PrintCommand("Finished Hopper LeftBlue / RightRed"));

	}




	AddSequential(new PrintCommand("Hopper Fire Commands!!!"));

	AddSequential(new LoaderWheel(BoilerLoaderSpeed, 10)); //get laundry tub spinning up
	AddSequential(new ShooterGroup()); //open upper hopper to drop balls into laundry tub

	AddSequential(new PrintCommand("Hopper Fire Commands Done"));



}
