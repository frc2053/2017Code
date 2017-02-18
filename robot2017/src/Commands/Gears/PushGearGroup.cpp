
#include "PushGearGroup.h"
#include "FlapperSolenoid.h"
#include "PusherSolenoid.h"
#include "../Autonomous/DoNothingAuto.h"

PushGearGroup::PushGearGroup() {
	AddSequential(new FlapperSolenoid(1));
	AddSequential(new DoNothingAuto(0.5));
	AddSequential(new PusherSolenoid(1));
}
