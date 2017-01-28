#include "GearRetractGroup.h"
#include "FlapperSolenoid.h"
#include "ChuteSolenoid.h"

GearRetractGroup::GearRetractGroup() {
	AddParallel(new ChuteSolenoid(0));
	Wait(.5);
	AddParallel(new FlapperSolenoid(0));
}
