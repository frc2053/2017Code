#include "../Shooter/ShooterWheel.h"

ShooterWheel::ShooterWheel(float speed, float time) {
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	isDone = false;
	timeTarget = time;
	timeCurrent = 0;
	inputSpeed = speed;
	timer->Reset();
	timer->Start();

}

void ShooterWheel::Initialize() {
	isDone = false;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
}

void ShooterWheel::Execute()
{
	if(inputSpeed == 0)
	{
		isDone = true;
	}

	if(!inputSpeed == 0) {
		inputSpeed = SmartDashboard::GetNumber("Shooter RPM", 4000);
	}
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		if(RobotMap::shooterSubsystemFlywheelTalon->GetSpeed() > 10) {
			Robot::shooterSubsystem->SetServoAngle(171);
		}
		else if(RobotMap::shooterSubsystemFlywheelTalon->GetSpeed() < 10) {
			Robot::shooterSubsystem->SetServoAngle(0);

		}
		Robot::shooterSubsystem->RunShooterMotor(inputSpeed);
		//isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::shooterSubsystem->RunShooterMotor(0);

			Robot::shooterSubsystem->SetServoAngle(100);

			//isDone = true;
		}
		else {
			//if(RobotMap::shooterSubsystemFlywheelTalon->GetSpeed() > 2000) {
						Robot::shooterSubsystem->SetServoAngle(145);
			//		}
			Robot::shooterSubsystem->RunShooterMotor(inputSpeed);
			//isDone = false;
		}
	}
}

bool ShooterWheel::IsFinished() {
	return isDone;
}

void ShooterWheel::End(){
	Robot::shooterSubsystem->SetServoAngle(90);
	timer->Stop();
}

void ShooterWheel::Interrupted() {
	timer->Stop();
}

