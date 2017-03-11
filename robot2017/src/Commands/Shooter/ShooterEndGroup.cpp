#include "ShooterEndGroup.h"
#include "ShooterGroup.h"
#include "ShooterWheel.h"
#include "LoaderWheel.h"
#include "LoaderServo.h"
#include "../Autonomous/DoNothingAuto.h"
#include "HopperServo.h"


ShooterEndGroup::ShooterEndGroup() {
	AddSequential(new LoaderServo(0));
	AddSequential(new HopperServo(0));
	AddParallel(new DoNothingAuto(0));
	AddParallel(new ShooterWheel(0, 0));
	AddParallel(new DoNothingAuto(0));
	AddSequential(new DoNothingAuto(0));
	AddSequential(new LoaderWheel(0, 0));
	//Robot::shooterSubsystem->SetServoAngle(0);
}
