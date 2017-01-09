#ifndef DRIVECOMMAND_H
#define DRIVECOMMAND_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class DriveCommand: public Command {
public:
	DriveCommand();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
