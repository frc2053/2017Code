#include "ShooterEndGroup.h"
#include "ShooterGroup.h"
#include "ShooterWheel.h"
#include "LoaderWheel.h"
#include "LoaderServo.h"
#include "../Autonomous/DoNothingAuto.h"

ShooterEndGroup::ShooterEndGroup() {
	AddSequential(new ShooterWheel(0, 0));
	AddSequential(new LoaderWheel(0, 0));
	AddSequential(new LoaderServo(90));
}