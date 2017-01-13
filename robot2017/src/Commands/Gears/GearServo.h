#ifndef GearServo_H
#define GearServo_H

#include "Commands/Command.h"
#include "../../Robot.h"

class GearServo : public Command {
public:
	GearServo(float inputAngle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	float angle;
};

#endif  // GearServo_H
