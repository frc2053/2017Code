#include "BLUE_DriveToBoiler.h"

#include "DriveCommandAuto.h"
#include "../Drive/AlignCenter.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"
#include "../Shooter/LoaderServo.h"
#include "../Autonomous/DoNothingAuto.h"
#include "../Shooter/ShooterGroup.h"

#define BoilerShooterSpeed 5200
#define BoilerLoaderSpeed  3200

BLUE_DriveToBoiler::BLUE_DriveToBoiler(std::string pos) {
	std::string gearPos = pos;

	if(!gearPos.compare("center")) {  //returns 0 if equal so thats why we are doing !

		AddSequential(new PrintCommand("Starting BLUE Boiler From Center"));

		AddSequential(new DriveCommandAuto(0, 0, 0, .5, -90));//Turn 90 Toward Boiler
		AddSequential(new DriveCommandAuto(-1, 0, 0, 1, -90));//Drive Forward Across Field
		AddParallel(new ShooterWheel(BoilerShooterSpeed, 12)); //spins up shooter wheels and runs for 12 seconds or until auto done
		AddSequential(new DriveCommandAuto(0, 0, 0, .5, -135));//ROT TO BOILER
		//AddParallel(new ShooterWheel(BoilerShooterSpeed, 12)); //spins up shooter wheels and runs for 12 seconds or until auto done

		AddSequential(new DriveCommandAuto(-.5, .5, 0, .75, -135));//DRIVES TO BOILER

		AddSequential(new PrintCommand("Finished Boiler From Center"));

	}



	if(!gearPos.compare("leftblue")) { //if (left and blue) or (right and red)

		AddSequential(new PrintCommand("Starting Boiler LeftBlue / RightRed"));

		AddSequential(new DriveCommandAuto(0, 0, 0, .5, 180)); //rotates to 180
		AddSequential(new DriveCommandAuto(0, .5, 0, .5, 180)); //drives to drive station wall
		AddParallel(new ShooterWheel(BoilerShooterSpeed, 12)); //spins up shooter wheels and runs for 12 seconds or until auto done

		AddSequential(new DriveCommandAuto(0, 0, 0, .5, -135)); //rotates to boiler

		AddSequential(new DriveCommandAuto(-.5, .5, 0, 1.5, -135));//DRIVES TO BOILER
		AddSequential(new DriveCommandAuto(0, 0, 0, .25, -135)); //drive onto airship

		AddSequential(new PrintCommand("Finished Boiler LeftBlue / RightRed"));

	}



	if(!gearPos.compare("rightblue")) { //if (right and blue) or (left and red)

		AddSequential(new PrintCommand("Starting Boiler RightBlue / LeftRed"));

		AddSequential(new DriveCommandAuto(-.5, .5, 0, 1.6, -135)); //drive onto airship
		AddSequential(new DriveCommandAuto(-.75, 0, 0, 2, -90)); //drive onto airship

		AddParallel(new ShooterWheel(BoilerShooterSpeed, 12)); //spins up shooter wheels and runs for 12 seconds or until auto done
		AddSequential(new DriveCommandAuto(0, 0, 0, .25, -135)); //drive onto airship


		AddSequential(new PrintCommand("Finished Boiler RightBlue / LeftRed"));

	}

	AddSequential(new ShooterGroup());
}
