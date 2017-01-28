#ifndef ChuteSolenoid_H
#define ChuteSolenoid_H

#include "Commands/Command.h"
#include "../../Robot.h"

class ChuteSolenoid : public Command {
public:
	ChuteSolenoid(bool mode, bool direction);
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
