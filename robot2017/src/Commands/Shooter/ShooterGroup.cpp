#include "ShooterGroup.h"
#include "ShooterWheel.h"
#include "LoaderWheel.h"
#include "LoaderServo.h"
#include "../Autonomous/DoNothingAuto.h"


ShooterGroup::ShooterGroup() {
	AddSequential(new ShooterWheel(1, 0));
	AddSequential(new DoNothingAuto(.7));
	AddSequential(new LoaderWheel(1, 0));
}
