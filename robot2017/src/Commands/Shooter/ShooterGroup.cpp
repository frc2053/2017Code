#include "ShooterGroup.h"
#include "ShooterWheel.h"
#include "LoaderWheel.h"
#include "LoaderServo.h"
#include "../Autonomous/DoNothingAuto.h"
#include "HopperServo.h"


ShooterGroup::ShooterGroup() {
	AddSequential(new PrintCommand("MADE IT TO SHOOTER GROUP"));
	AddParallel(new DoNothingAuto(0));
	AddParallel(new ShooterWheel(1, 0));
	AddSequential(new DoNothingAuto(.5));
	AddParallel(new DoNothingAuto(0));
	AddParallel(new LoaderWheel(1, 0));
	AddSequential(new DoNothingAuto(0.01));
	//AddSequential(new LoaderServo(150));
	AddParallel(new PrintCommand("MADE IT TO THE HOPPER"));
	AddParallel(new HopperServo(.25));
	AddParallel(new PrintCommand("FINISHED SHOOTER GROUP"));
}
