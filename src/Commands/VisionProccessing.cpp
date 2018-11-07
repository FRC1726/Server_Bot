/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "VisionProccessing.h"
#include <SmartDashboard/SmartDashboard.h>
#include <Preferences.h>

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
	bool detected = SmartDashboard::GetBoolean("Blocks Detected", false);
	double offset = SmartDashboard::GetNumber("X position", 0);
	double distance = SmartDashboard::GetNumber("Distance", 0);

	double turnSpeed = 0;
	double driveSpeed = 0;

	if(detected){
		if(offset < -5){
			turnSpeed = driveProfile(offset / 159.0);
		}
		else if(offset > 5){
			turnSpeed = driveProfile(offset / 160.0);
		}
		else{
			turnSpeed = 0;
		}

		if(distance <= 150){
			driveSpeed = -.035;
		}else if(distance >= 220){
			driveSpeed = .035;
		}else{
			driveSpeed = 0;
		}

		drivetrain.arcadeDrive(driveSpeed, turnSpeed);
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
	drivetrain.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionProccessing::Interrupted() {
	drivetrain.Stop();
}

double VisionProccessing::driveProfile(double input) {
	if(fabs(input) <= deadzone){
			return 0;
		}

	double out = (maxSpeed - minSpeed) * fabs(input) + minSpeed;

	if(input > 0){
		return out;
	}
	if(input < 0){
		return -out;
	} else {
		return 0;
	}
}

void VisionProccessing::getPreferences() {
	//Set Drive Profile parameters
	maxSpeed = Preferences::GetInstance()->GetDouble("Joysticks/Max Speed", 1);
	minSpeed = Preferences::GetInstance()->GetDouble("Joysticks/Min Speed", 0.35);
	deadzone = Preferences::GetInstance()->GetDouble("Joysticks/Deadzone", .025);
	acceleration = Preferences::GetInstance()->GetDouble("Joysticks/acceleration", .025);
}

void VisionProccessing::checkKeys() {
	//Drive Profile Values
	if (!Preferences::GetInstance()->ContainsKey("VisionProccessing/Max Speed")) {
		Preferences::GetInstance()->PutDouble("VisionProccessing/Max Speed", 1.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("VisionProccessing/Min Speed")) {
		Preferences::GetInstance()->PutDouble("VisionProccessing/Min Speed", 0.35);
	}
	if (!Preferences::GetInstance()->ContainsKey("VisionProccessing/Deadzone")) {
		Preferences::GetInstance()->PutDouble("VisionProccessing/Deadzone", .025);
	}
	if (!Preferences::GetInstance()->ContainsKey("VisionProccessing/acceleration")) {
		Preferences::GetInstance()->PutDouble("VisionProccessing/acceleration", 1.0);
	}
}

