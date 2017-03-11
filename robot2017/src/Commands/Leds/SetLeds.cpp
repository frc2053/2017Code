#include "SetLeds.h"

SetLeds::SetLeds(std::string input_data, int isPressed)
{
	Requires(Robot::ledSubsystem.get());
	data = input_data;
	isDone = false;
	Pressed = isPressed;
}

void SetLeds::Initialize()
{

}

void SetLeds::Execute()
{
	isDone = false;
	if(Pressed != 1)
	{
		std::cout << "MADE IT TO THE SEND DATA" << std::endl;
		Robot::ledSubsystem->SendData(data);
	}
	isDone = true;
}

bool SetLeds::IsFinished()
{
	return isDone;
}

void SetLeds::End()
{

}

void SetLeds::Interrupted()
{

}
