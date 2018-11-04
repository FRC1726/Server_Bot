#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>

class OI {
public:
	OI();
	double getAxis(int);
	int getPOV();
	bool getButtonState(int);
private:
	Joystick driver;
	JoystickButton driver_A;
	JoystickButton driver_B;
	JoystickButton driver_X;
	JoystickButton driver_Y;
	JoystickButton driver_LB;
	JoystickButton driver_RB;
	JoystickButton driver_SELECT;
	JoystickButton driver_START;

};

#endif
