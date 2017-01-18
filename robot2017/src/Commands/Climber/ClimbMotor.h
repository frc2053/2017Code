#ifndef ClimbMotor_H
#define ClimbMotor_H

#include "Commands/Command.h"
#include "../../Robot.h"

class ClimbMotor : public Command {
public:
	ClimbMotor(float speed, float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	float inputSpeed;
	bool isDone;
};

#endif
