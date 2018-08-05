#ifndef ROBOT_H
#define ROBOT_H

#include <memory>
#include <Commands/Command.h>
#include <TimedRobot.h>
#include <SmartDashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
public:
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
private:
	std::shared_ptr<Command> autonomousCommand;
};

#endif
