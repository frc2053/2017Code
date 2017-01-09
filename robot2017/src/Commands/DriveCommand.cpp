#include "DriveCommand.h"

DriveCommand::DriveCommand(): Command() {
	Requires(Robot::drivebaseSubsystem.get());
}

void DriveCommand::Initialize() {

}

void DriveCommand::Execute() {

}

bool DriveCommand::IsFinished() {
    return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {

}
