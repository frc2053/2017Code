#ifndef FlapperSolenoid_H
#define FlapperSolenoid_H

#include "Commands/Command.h"
#include "../../Robot.h"

class FlapperSolenoid : public Command {
public:
	FlapperSolenoid(bool mode, bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	bool currentMode;
	bool currentDirection;
};

#endif
