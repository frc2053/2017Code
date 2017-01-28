#ifndef ChuteSolenoid_H
#define ChuteSolenoid_H

#include "Commands/Command.h"
#include "../../Robot.h"

class ChuteSolenoid : public Command {
public:
	ChuteSolenoid(bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	bool currentDirection;
};

#endif
