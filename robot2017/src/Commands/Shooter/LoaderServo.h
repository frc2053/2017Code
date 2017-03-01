#ifndef LoaderServo_H
#define LoaderServo_H

#include "../../Robot.h"
#include "Commands/Command.h"

class LoaderServo : public frc::Command {
public:
	LoaderServo(float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float _angle;
};

#endif
