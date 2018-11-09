/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/VisionProcessing.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Preferences.h>

VisionProcessing::VisionProcessing() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&drivetrain);
	checkKeys();
}

// Called just before this Command runs the first time
void VisionProcessing::Initialize() {
	getPreferences();
}

// Called repeatedly when this Command is scheduled to run
void VisionProcessing::Execute() {
	bool detected = SmartDashboard::GetBoolean("Blocks Detected", false);
	double offset = SmartDashboard::GetNumber("X position", 0);
	double distance = SmartDashboard::GetNumber("Distance", 0);

	double turnSpeed = 0;
	double driveSpeed = 0;

	if(detected){
		if(offset < -5){
			turnSpeed = driveProfile(offset / 159.0, minTurnSpeed, maxTurnSpeed);
		}
		else if(offset > 5){
			turnSpeed = driveProfile(offset / 160.0, minTurnSpeed, maxTurnSpeed);
		}
		else{
			turnSpeed = 0;
		}

		if(distance <= minDistance){
			driveSpeed = driveProfile((minDistance - distance) / minDistance , minDistanceSpeed, maxDistanceSpeed);
		}else if(distance >= maxDistance){
			driveSpeed = driveProfile((maxDistance - distance) / maxDistance, minDistanceSpeed, maxDistanceSpeed);
		}else{
			driveSpeed = 0;
		}

		drivetrain.arcadeDrive(-driveSpeed, turnSpeed);
	}
	else{
		drivetrain.Stop();
	}

}

// Make this return true when this Command no longer needs to run execute()
bool VisionProcessing::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void VisionProcessing::End() {
	drivetrain.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionProcessing::Interrupted() {
	drivetrain.Stop();
}

double VisionProcessing::driveProfile(double input, double minSpeed, double maxSpeed) {
	double cutoff = fabs(input);
	if(cutoff > 1){
		cutoff = 1;
	}

	if(cutoff <= deadzone){
			return 0;
		}

	double out = (maxSpeed - minSpeed) * cutoff + minSpeed;

	if(input > 0){
		return out;
	}
	if(input < 0){
		return -out;
	} else {
		return 0;
	}
}

void VisionProcessing::getPreferences() {
	//Set Drive Profile parameters
	maxDistanceSpeed = Preferences::GetInstance()->GetDouble("Vision Processing/Distance/Max Speed", 1);
	minDistanceSpeed = Preferences::GetInstance()->GetDouble("Vision Processing/Distance/Min Speed", 0.35);
	deadzone = Preferences::GetInstance()->GetDouble("Vision Processing/Deadzone", .025);
	minDistance = Preferences::GetInstance()->GetDouble("Vision Processing/Distance/Distance Min",10);
	maxDistance = Preferences::GetInstance()->GetDouble("Vision Processing/Distance/Distance Max",15);
	minTurnSpeed = Preferences::GetInstance()->GetDouble("Vision Processing/Turn/Min Turn Speed",0.35);
	maxTurnSpeed = Preferences::GetInstance()->GetDouble("Vision Processing/Turn/Max Turn Speed",0.35);

}

void VisionProcessing::checkKeys() {
	//Drive Profile Values
	if (!Preferences::GetInstance()->ContainsKey("Vision Processing/Distance/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Vision Processing/Distance/Max Speed", 1.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Vision Processing/Distance/Min Speed")) {
		Preferences::GetInstance()->PutDouble("Vision Processing/Distance/Min Speed", 0.35);
	}
	if (!Preferences::GetInstance()->ContainsKey("Vision Processing/Deadzone")) {
		Preferences::GetInstance()->PutDouble("Vision Processing/Deadzone", .025);
	}
	//Follow distances and speeds
	if (!Preferences::GetInstance()->ContainsKey("Vision Processing/Distance/Distance Min")) {
			Preferences::GetInstance()->PutDouble("Vision Processing/Distance/Distance Min", 10);
	}
	if (!Preferences::GetInstance()->ContainsKey("Vision Processing/Distance/Distance Max")) {
			Preferences::GetInstance()->PutDouble("Vision Processing/Distance/Distance Max", 15);
	}
	//Turn Speed
	if (!Preferences::GetInstance()->ContainsKey("Vision Processing/Turn/Min Turn Speed")) {
				Preferences::GetInstance()->PutDouble("Vision Processing/Turn/Min Turn Speed", 0.35);
		}
	if (!Preferences::GetInstance()->ContainsKey("Vision Processing/Turn/Max Turn Speed")) {
				Preferences::GetInstance()->PutDouble("Vision Processing/Turn/Max Turn Speed", 0.35);
		}
}

