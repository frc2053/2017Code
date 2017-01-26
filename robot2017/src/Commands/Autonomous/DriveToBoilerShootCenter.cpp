#include "DriveToBoilerShootCenter.h"

#include "DriveCommandAuto.h"
#include "../Drive/AlignCenter.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"

DriveToBoilerShootCenter::DriveToBoilerShootCenter() {
	AddSequential(new DriveCommandAuto(0, .5, 0, .5, 0));
	if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
		AddSequential(new DriveCommandAuto(-.5, 0, 0, 1, 0)); //drives left
		AddSequential(new AlignCenter(60)); //aligns with boiler
		AddSequential(new DriveCommandAuto(0, -.5, 0, 1, 60)); //drives up to boiler
		AddParallel(new LoaderWheel(1, 2)); //loads
		AddParallel(new ShooterWheel(5000, 5)); //fires
	}
	if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
		AddSequential(new DriveCommandAuto(.5, 0, 0, 1, 0)); //drives right
		AddSequential(new AlignCenter(-60)); //aligns with boiler
		AddSequential(new DriveCommandAuto(0, -.5, 0, 1, -60)); //drives up to boiler
		AddParallel(new LoaderWheel(1, 2)); //loads
		AddParallel(new ShooterWheel(5000, 5)); //fires
	}
}
