//#include <Commands/DriveWithJoysticks.h>
#include "DriveTrain.h"
#include "../RobotMap.h"
#include <SerialPort.h>
#include <SmartDashboard/SmartDashboard.h>

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	leftController(DRIVE_LEFT),
	rightController(DRIVE_RIGHT),
	drive(leftController, rightController),
	leftEncoder(LA_CHANNEL, LB_CHANNEL),
	rightEncoder(RA_CHANNEL, RB_CHANNEL),
	gyro(SerialPort::Port::kUSB1),
	pidWrite(),
	pidController(0, 0, 0, &gyro, &pidWrite)
{
	leftEncoder.SetReverseDirection(true);
	leftEncoder.SetDistancePerPulse(3.1415/60);
	rightEncoder.SetDistancePerPulse(3.1415/60);

	pidController.SetInputRange(-180, 180);
	pidController.SetOutputRange(0,1);
	pidController.SetContinuous(true);
}
