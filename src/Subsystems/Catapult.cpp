#include "Catapult.h"
#include "../RobotMap.h"

Catapult::Catapult() : Subsystem("Catapult"),
	arm(CATAPULT_ARM)
{

}

void Catapult::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Catapult::extendArm(){
	arm.Set(true);
}

void Catapult::retractArm(){
	arm.Set(false);
}
