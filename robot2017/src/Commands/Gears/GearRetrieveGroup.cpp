#include "GearRetrieveGroup.h"
#include "FlapperSolenoid.h"
#include "ChuteSolenoid.h"
#include "../Autonomous/DoNothingAuto.h"

GearRetrieveGroup::GearRetrieveGroup() {
	AddSequential(new ChuteSolenoid(1));
}
