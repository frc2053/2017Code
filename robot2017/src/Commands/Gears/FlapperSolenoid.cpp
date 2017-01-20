#include "FlapperSolenoid.h"

FlapperSolenoid::FlapperSolenoid(bool input) {
	std::cout << "constructor" << std::endl;
	Requires(Robot::gearSubsystem.get());
	isDone = false;
	direction = input;
}

void FlapperSolenoid::Initialize() {
	std::cout << "init" << std::endl;
	isDone = false;
	direction = 0;
}

void FlapperSolenoid::Execute() {
	std::cout << "execute" << std::endl;
	Robot::gearSubsystem->SetFlapperUp();
	isDone = true;
}

bool FlapperSolenoid::IsFinished() {
	std::cout << "is finished" << std::endl;
	return isDone;
}

void FlapperSolenoid::End() {
	Robot::gearSubsystem->SetFlapperDown();

	std::cout << "end" << std::endl;
}

void FlapperSolenoid::Interrupted() {
	Robot::gearSubsystem->SetFlapperDown();

	std::cout << "interrupt" << std::endl;

}
