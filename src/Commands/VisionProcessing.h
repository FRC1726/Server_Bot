/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "CommandBase.h"

class VisionProcessing : public CommandBase {
public:
	VisionProcessing();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:

	double deadzone;
	double acceleration;
	double minDistance;
	double maxDistance;
	double minDistanceSpeed;
	double maxDistanceSpeed;
	double adjustmentSpeed;
	double minTurnSpeed;
	double maxTurnSpeed;

	double driveProfile(double, double, double);
	void getPreferences();
	void checkKeys();
};

