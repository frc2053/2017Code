#include "TurretGear.h"

TurretGear::TurretGear() {
	Requires(Robot::shooterSubsystem.get());
}

void TurretGear::Initialize() {

}

void TurretGear::Execute() {
	double angleToTarget = Robot::visionTable->GetNumber("angleToTarget", 0.0);
	double currentAngle = Robot::shooterSubsystem->GetAngleOfTurret();
	Robot::shooterSubsystem->RunTurretMotor(currentAngle + angleToTarget);
}

bool TurretGear::IsFinished() {
	return true;
}

void TurretGear::End() {

}

void TurretGear::Interrupted() {

}
