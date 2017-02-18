#include "RetractGearGroup.h"
#include "FlapperSolenoid.h"
#include "PusherSolenoid.h"
#include "../Autonomous/DoNothingAuto.h"

RetractGearGroup::RetractGearGroup() {
	AddSequential(new FlapperSolenoid(0));
	AddSequential(new PusherSolenoid(0));
}
