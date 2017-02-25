#include "DriveToBoilerShootCenter.h"

#include "DriveCommandAuto.h"
#include "../Drive/AlignCenter.h"
#include "../Shooter/LoaderWheel.h"
#include "../Shooter/ShooterWheel.h"
#include "../Autonomous/DoNothingAuto.h"

DriveToBoilerShootCenter::DriveToBoilerShootCenter() {
	if(Robot::currentAlliance == frc::DriverStation::Alliance::kBlue) {
		std::cout << "REACHED THE DRIVE TO BOILER SHOOT CENTER" <<  std::endl;
		AddSequential(new DriveCommandAuto(0, 0, 0, 1, 135)); //
		AddSequential(new DoNothingAuto(1));
		AddSequential(new DriveCommandAuto(0, -.5, 0, 2, 135));
		AddSequential(new DoNothingAuto(1));
		std::cout << "END OF DRIVE COMMANDS" << std::endl;
		//AddSequential(new AlignCenter(135)); //aligns with boiler
		//AddSequential(new DriveCommandAuto(0, -.5, 0, 1, -135)); //drives up to boiler
		//align again?
		AddSequential(new ShooterWheel(SmartDashboard::GetNumber("Shooter RPM", 4000), 5)); //fires
		AddSequential(new DoNothingAuto(.5));  //lets the shooter get to speed
		AddSequential(new LoaderWheel(SmartDashboard::GetNumber("Loader RPM", 3000), 2)); //loads
	}
	if(Robot::currentAlliance == frc::DriverStation::Alliance::kRed) {
		AddSequential(new DriveCommandAuto(.5, 0, 0, 1, 0)); //drives right
		//AddSequential(new AlignCenter(-135)); //aligns with boiler
		AddSequential(new DriveCommandAuto(0, -.5, 0, 1, 135)); //drives up to boiler
		//align again?
		AddSequential(new ShooterWheel(SmartDashboard::GetNumber("Shooter RPM", 4000), 5)); //fires
		AddSequential(new DoNothingAuto(.5));  //lets the shooter get to speed
		AddSequential(new LoaderWheel(SmartDashboard::GetNumber("Loader RPM", 3000), 2)); //loads
	}
}
