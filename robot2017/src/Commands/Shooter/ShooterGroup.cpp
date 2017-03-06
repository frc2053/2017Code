#include "ShooterGroup.h"
#include "ShooterWheel.h"
#include "LoaderWheel.h"
#include "LoaderServo.h"
#include "../Autonomous/DoNothingAuto.h"


ShooterGroup::ShooterGroup() {
	AddSequential(new ShooterWheel(1, 0));
	AddSequential(new DoNothingAuto(2.25));
	AddSequential(new LoaderWheel(4000, 0));
	Robot::shooterSubsystem->SetServoAngle(0);

}
