#ifndef SetLeds_H
#define SetLeds_H

#include "Commands/Command.h"
#include "../../Robot.h"

class SetLeds: public Command
{
public:
	SetLeds(std::string data, int isPressed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	int Pressed;
	std::string data;
};

#endif
