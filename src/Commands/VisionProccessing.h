/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "CommandBase.h"

class VisionProccessing : public CommandBase {
public:
	VisionProccessing();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	double minSpeed;
	double maxSpeed;
	double deadzone;
	double acceleration;

	double driveProfile(double);
	void getPreferences();
	void checkKeys();
};

