#ifndef LoaderWheel_H
#define LoaderWheel_H

#include "Commands/Command.h"
#include "../../Robot.h"

class LoaderWheel : public Command {
public:
	LoaderWheel(float speed  =  0, float time = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
		std::shared_ptr<Timer> timer;
		float timeCurrent;
		float timeTarget;
		float inputSpeed; //not rpm for loader, using max speed for now
		bool isDone;
		Command* hopperServoCmd;
		Command* ledCommand;
		int isPassed;
};

#endif  // LoaderWheel_H
