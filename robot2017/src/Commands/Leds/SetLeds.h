#ifndef SetLeds_H
#define SetLeds_H

#include "Commands/Command.h"
#include "../../Robot.h"

class SetLeds: public Command
{
public:
	SetLeds(std::string data);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	std::string data;
};

#endif
