#include "GearRetrieveGroup.h"
#include "FlapperSolenoid.h"
#include "ChuteSolenoid.h"

GearRetrieveGroup::GearRetrieveGroup() {
	AddSequential(new FlapperSolenoid(1));
	Wait(.5);
	AddSequential(new ChuteSolenoid(1));
}
