#ifndef HopperServo_H
#define HopperServo_H

#include "../../Robot.h"
#include "Commands/Command.h"

class HopperServo : public Command {
public:
	HopperServo(float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float _angle;
	bool isDone;
};

#endif
