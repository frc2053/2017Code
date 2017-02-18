#include "SetLeds.h"

SetLeds::SetLeds(std::string input_data)
{
	Requires(Robot::ledSubsystem.get());
	data = input_data;
	isDone = false;
}

void SetLeds::Initialize()
{

}

void SetLeds::Execute()
{
	isDone = false;
	Robot::ledSubsystem->SendData(data);
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
