#include "CommandBase.h"

OI CommandBase::oi;
DriveTrain CommandBase::drivetrain;
std::unique_ptr<PowerDistributionPanel> CommandBase::pdp = std::make_unique<PowerDistributionPanel>(1);
Catapult CommandBase::catapult;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
