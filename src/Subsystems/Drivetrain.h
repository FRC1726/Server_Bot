#pragma once

#include <Commands/Subsystem.h>
#include <VictorSP.h>

class Drivetrain : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Drivetrain();
	void InitDefaultCommand() override;
};

