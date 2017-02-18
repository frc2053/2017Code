#ifndef LedSubsystem_H
#define LedSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LedSubsystem: public Subsystem
{
private:
	std::shared_ptr<SerialPort> arduino;
public:
	LedSubsystem();
	void InitDefaultCommand();
	void SendData(std::string data);
};

#endif
