#ifndef PusherSolenoid_H
#define PusherSolenoid_H

#include "Commands/Command.h"
#include "../../Robot.h"

class PusherSolenoid : public Command {
public:
	PusherSolenoid(bool input);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	bool direction;
};

#endif
