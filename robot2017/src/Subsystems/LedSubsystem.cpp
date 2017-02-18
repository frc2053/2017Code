#include "LedSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/Leds/SetLeds.h"

LedSubsystem::LedSubsystem() : Subsystem("LEDSubsystem")
{
	arduino = RobotMap::arduino;
}

void LedSubsystem::InitDefaultCommand()
{

}

void LedSubsystem::SendData(std::string data) {
	arduino->Write(data);
}
