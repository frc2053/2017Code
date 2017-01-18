#ifndef AlignCenter_H
#define AlignCenter_H

#include "Commands/Command.h"
#include "../../Robot.h"

class AlignCenter : public Command {
public:
	AlignCenter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float CalculateSpeedValue(int distToCenter);
private:
	int distanceToCenter;
	float adjyaw;
	float speedX;
	bool isDone;
};

#endif
