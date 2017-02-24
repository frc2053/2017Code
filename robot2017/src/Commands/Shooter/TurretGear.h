#ifndef TurretGear_H
#define TurretGear_H

#include "Commands/Command.h"
#include "../../Robot.h"

class TurretGear : public Command {
public:
	TurretGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:

};

#endif
