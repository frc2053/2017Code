#include "DriveToBoilerShootCenter.h"

#include "DriveCommandAuto.h"
#include "../Drive/AlignCenter.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"
#include "../Shooter/LoaderServo.h"
#include "../Autonomous/DoNothingAuto.h"
#include "../Shooter/ShooterGroup.h"

#define BoilerShooterSpeed 4200
#define BoilerLoaderSpeed  3000

DriveToBoilerShootCenter::DriveToBoilerShootCenter(std::string lrc) {

	int rev = 1; //default - serves as multiplier for field side to side reversals, because field isnt symmetric red to blue
	std::string gearPos = lrc;

	AddSequential(new PrintCommand("In Boiler Processing"));


	if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
		rev = 1; // tested auto on blue setup, this remains positive
	}


	if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
		rev = -1; // reverse some directions for red field setup
	}


	if(!gearPos.compare("center")) {  //returns 0 if equal so thats why we are doing !

		AddSequential(new PrintCommand("Starting Boiler From Center"));

		AddSequential(new DriveCommandAuto(0, 0, 0, .5, rev*(-90)));//Turn 90 Toward Boiler
		AddSequential(new DriveCommandAuto(rev*(-1), 0, 0, 1, rev*(-90)));//Drive Forward Across Field
		AddParallel(new ShooterWheel(BoilerShooterSpeed, 12)); //spins up shooter wheels and runs for 12 seconds or until auto done
		AddSequential(new DriveCommandAuto(0, 0, 0, .5, rev*(-135)));//ROT TO BOILER
		//AddParallel(new ShooterWheel(BoilerShooterSpeed, 12)); //spins up shooter wheels and runs for 12 seconds or until auto done

		AddSequential(new DriveCommandAuto(rev*(-.5), .5, 0, .75, rev*(-135)));//DRIVES TO BOILER

		AddSequential(new PrintCommand("Finished Boiler From Center"));

	}



	if((!gearPos.compare("leftblue")) || (!gearPos.compare("rightred"))) { //if (left and blue) or (right and red)

		AddSequential(new PrintCommand("Starting Boiler LeftBlue / RightRed"));

		AddSequential(new DriveCommandAuto(0, 0, 0, .5, 180)); //rotates to 180
		AddSequential(new DriveCommandAuto(0, .5, 0, .5, 180)); //drives to drive station wall
		AddParallel(new ShooterWheel(BoilerShooterSpeed, 12)); //spins up shooter wheels and runs for 12 seconds or until auto done

		AddSequential(new DriveCommandAuto(0, 0, 0, .5, rev*(-135))); //rotates to boiler

		AddSequential(new DriveCommandAuto(rev*(-.5), .5, 0, 1.5, rev*(-135)));//DRIVES TO BOILER
		AddSequential(new DriveCommandAuto(0, 0, 0, .25, rev*(-135))); //drive onto airship

		AddSequential(new PrintCommand("Finished Boiler LeftBlue / RightRed"));

	}



	if((!gearPos.compare("rightblue")) || (!gearPos.compare("leftred"))) { //if (right and blue) or (left and red)

		AddSequential(new PrintCommand("Starting Boiler RightBlue / LeftRed"));

		AddSequential(new DriveCommandAuto(rev*(-.5), .5, 0, 1.6, rev*(-135))); //drive onto airship
		AddSequential(new DriveCommandAuto(rev*(-.75), 0, 0, 2, rev*(-90))); //drive onto airship

		AddParallel(new ShooterWheel(BoilerShooterSpeed, 12)); //spins up shooter wheels and runs for 12 seconds or until auto done
		AddSequential(new DriveCommandAuto(0, 0, 0, .25, rev*(-135))); //drive onto airship


		AddSequential(new PrintCommand("Finished Boiler RightBlue / LeftRed"));

	}


	AddSequential(new PrintCommand("Auto Fire Commands!!!"));

	AddSequential(new ShooterGroup());
	//AddSequential(new LoaderWheel(BoilerLoaderSpeed, 10)); //get laundry tub spinning up
	//AddSequential(new LoaderServo(90)); //open upper hopper to drop balls into laundry tub

	AddSequential(new PrintCommand("Auto Fire Commands Done"));

}
