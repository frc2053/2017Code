#ifndef HopperServo_H
#define HopperServo_H

#include "../../Robot.h"
#include "Commands/Command.h"

class HopperServo : public Command {
public:
	HopperServo(float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
	bool isDone;
	float timeCurrent;
	float timeTarget;
	bool isDeployed;
};

#endif
