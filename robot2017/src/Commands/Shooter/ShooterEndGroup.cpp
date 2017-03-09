#include "ShooterEndGroup.h"
#include "ShooterGroup.h"
#include "ShooterWheel.h"
#include "LoaderWheel.h"
#include "LoaderServo.h"
#include "../Autonomous/DoNothingAuto.h"


ShooterEndGroup::ShooterEndGroup() {
	AddParallel(new DoNothingAuto(0));
	AddParallel(new ShooterWheel(0, 0));
	AddParallel(new DoNothingAuto(0));
	AddSequential(new DoNothingAuto(0));
	AddSequential(new LoaderWheel(0, 0));
<<<<<<< HEAD
	Robot::shooterSubsystem->SetServoAngle(0);

=======
	AddSequential(new LoaderServo(90));
>>>>>>> origin/master
}
