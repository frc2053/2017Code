#include "GearRetractGroup.h"
#include "FlapperSolenoid.h"
#include "ChuteSolenoid.h"
#include "../Autonomous/DoNothingAuto.h"

GearRetractGroup::GearRetractGroup() {
	AddSequential(new ChuteSolenoid(0));
}
