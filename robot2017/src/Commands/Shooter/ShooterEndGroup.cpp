#include "ShooterEndGroup.h"
#include "ShooterGroup.h"
#include "ShooterWheel.h"
#include "LoaderWheel.h"
#include "LoaderServo.h"

ShooterEndGroup::ShooterEndGroup() {
	AddSequential(new ShooterWheel(0, 0));
	AddSequential(new LoaderWheel(0, 0));
	Robot::shooterSubsystem->SetServoAngle(90);

}
