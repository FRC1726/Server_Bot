#include "LaunchCatapult.h"
#include "../Robot.h"

LaunchCatapult::LaunchCatapult() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&CommandBase::catapult);
}

// Called just before this Command runs the first time
void LaunchCatapult::Initialize() {
	catapult.extendArm();
}

// Called repeatedly when this Command is scheduled to run
void LaunchCatapult::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LaunchCatapult::IsFinished() {
	return TimeSinceInitialized() > 2;
}

// Called once after isFinished returns true
void LaunchCatapult::End() {
	catapult.retractArm();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LaunchCatapult::Interrupted() {
	catapult.retractArm();
}
