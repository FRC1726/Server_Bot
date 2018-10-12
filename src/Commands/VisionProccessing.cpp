/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "VisionProccessing.h"
#include <SmartDashboard/SmartDashboard.h>

VisionProccessing::VisionProccessing() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&drivetrain);
}

// Called just before this Command runs the first time
void VisionProccessing::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void VisionProccessing::Execute() {
	bool detected = SmartDashboard::getBoolean("Blocks Detected", false);
	double offset = SmartDashboard::getNumber("X Position", 0);

	if(detected){
		if(offset < -5){
			drivetrain.arcadeDrive(0, offset / 159.0);
		}
		else if(offset > 5){
			drivetrain.arcadeDrive(0, offset / 160.0);
		}
		else{
			drivetrain.Stop();
		}
	}
	else{
		drivetrain.Stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool VisionProccessing::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void VisionProccessing::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionProccessing::Interrupted() {

}
