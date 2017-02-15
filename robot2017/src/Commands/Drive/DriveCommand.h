#ifndef DRIVECOMMAND_H
#define DRIVECOMMAND_H


#include "Commands/Subsystem.h"
#include "../../Robot.h"

class DriveCommand: public Command {
public:
	DriveCommand();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	void SetAngleWithButton();
	void RotateCommand();
	void CheckRotateOverride();
	void CallToMecanumDrive();

	float xAxis;
	float yAxis;
	float rotAxis;
	float adjustedYaw;
	bool isRotDone;
	float setAngle;
	float setSpeed;
	float finalAutoRot;
	bool buttonAPressed;
	bool buttonBPressed;
	bool buttonXPressed;
	bool buttonYPressed;
	bool leftBumperPressed;
	bool rightBumperPressed;
};

#endif
