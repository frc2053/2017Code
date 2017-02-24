#include "DriveToBoilerShootCenter.h"

#include "DriveCommandAuto.h"
#include "../Drive/AlignCenter.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"

DriveToBoilerShootCenter::DriveToBoilerShootCenter() {
	if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
		AddSequential(new DriveCommandAuto(-.5, 0, 0, 1, 0)); //drives left
		AddSequential(new AlignCenter(135)); //aligns with boiler
		AddSequential(new DriveCommandAuto(0, -.5, 0, 1, -135)); //drives up to boiler
		//align again?
		AddParallel(new LoaderWheel(SmartDashboard::GetNumber("Loader RPM", 3000), 2)); //loads
		AddParallel(new ShooterWheel(SmartDashboard::GetNumber("Shooter RPM", 4000), 5)); //fires
	}
	if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
		AddSequential(new DriveCommandAuto(.5, 0, 0, 1, 0)); //drives right
		AddSequential(new AlignCenter(-135)); //aligns with boiler
		AddSequential(new DriveCommandAuto(0, -.5, 0, 1, 135)); //drives up to boiler
		//align again?
		AddParallel(new LoaderWheel(1, 2)); //loads
		AddParallel(new ShooterWheel(5000, 5)); //fires
	}
}
