#include "RetractGearGroup.h"
#include "FlapperSolenoid.h"
#include "PusherSolenoid.h"

RetractGearGroup::RetractGearGroup() {
	AddSequential(new FlapperSolenoid(0));
	Wait(.25);
	AddSequential(new PusherSolenoid(0));
}
