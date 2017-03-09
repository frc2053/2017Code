#include "ShooterGroup.h"
#include "ShooterWheel.h"
#include "LoaderWheel.h"
#include "LoaderServo.h"
#include "../Autonomous/DoNothingAuto.h"


ShooterGroup::ShooterGroup() {
	AddParallel(new DoNothingAuto(0));
	AddParallel(new ShooterWheel(1, 0));
	AddSequential(new DoNothingAuto(.5));
	AddSequential(new LoaderWheel(1, 0));


}
