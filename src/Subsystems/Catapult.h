#ifndef Catapult_H
#define Catapult_H

#include <Solenoid.h>
#include <Commands/Subsystem.h>

class Catapult : public Subsystem {
private:
	frc::Solenoid arm;

public:
	Catapult();
	void InitDefaultCommand();
	void extendArm();
	void retractArm();
};

#endif  // Catapult_H
