#include "DriveToBoilerClose.h"

#include "DriveCommandAuto.h"
#include "../Drive/AlignCenter.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"

DriveToBoilerClose::DriveToBoilerClose() {
	if(!(Robot::isRed)) {
		AddSequential(new DriveCommandAuto(0, .5, 0, .5, 60));
		AddSequential(new AlignCenter(60)); //aligns with boiler
		AddSequential(new DriveCommandAuto(0, -.5, 0, 1, 60)); //drives up to boiler
		AddParallel(new LoaderWheel(1, 2)); //loads
		AddParallel(new ShooterWheel(5000, 5)); //fires
	}
	if(Robot::isRed) {
		AddSequential(new DriveCommandAuto(0, .5, 0, .5, -60));
		AddSequential(new AlignCenter(-60)); //aligns with boiler
		AddSequential(new DriveCommandAuto(0, -.5, 0, 1, -60)); //drives up to boiler
		AddParallel(new LoaderWheel(1, 2)); //loads
		AddParallel(new ShooterWheel(5000, 5)); //fires
	}
}
