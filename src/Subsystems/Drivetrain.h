#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <Encoder.h>
#include <AHRS.h>
#include <VictorSP.h>
#include <PIDController.h>

class DriveTrain : public Subsystem {
public:
	enum encoderSide{
		kLeft,
		kRight
	};
	DriveTrain();
	void InitDefaultCommand();

	//Driving
	void arcadeDrive(double, double);
	void Stop();
	double getEncoderValue(encoderSide);
	double getVelocity(encoderSide);

	//Gyro


	//PID



private:
	VictorSP leftController;
	VictorSP rightController;
	DifferentialDrive drive;

	Encoder leftEncoder;
	Encoder rightEncoder;

	AHRS gyro;

	PidOut pidWrite;
	PIDController pidController;
};

#endif
