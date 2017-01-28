#include "PushGearGroup.h"
#include "FlapperSolenoid.h"
#include "PusherSolenoid.h"

PushGearGroup::PushGearGroup() {
	AddSequential(new FlapperSolenoid(1));
	Wait(.25);
	AddSequential(new PusherSolenoid(1));
}
