#include "JoystickDriver.c"

bool reversedControl = false;
task main()

{
	waitForStart();

	while(true) {

		bFloatDuringInactiveMotorPWM = false;
		getJoystickSettings(joystick);
		//Anti-RageQuit code (prevents movement when the joysticks are just a bit off)

		//CONTROLLER 1 JOYSTICK 1 - Drive (Forward/Backward)
		if((joystick.joy1_y1<10&&joystick.joy1_y1>-10)&&(joystick.joy1_x1<10&&joystick.joy1_x1>-10))
		{
			joystick.joy1_y1=0;
			joystick.joy1_x1=0;
		}
		//CONTROLLER 1 JOYSTICK 2 - Drive (Turning)
		if((joystick.joy1_x2<10&&joystick.joy1_x2>-10)&&(joystick.joy1_y2<10&&joystick.joy1_y2>-10))
		{
			joystick.joy1_x2=0;
			joystick.joy1_y2=0;
		}
		//CONTROLLER 2 JOYSTICK 2 - Flag lift motor
		if((joystick.joy2_x2<10&&joystick.joy2_x2>-10)&&(joystick.joy2_y2<10&&joystick.joy2_y2>-10))
		{
			joystick.joy2_x2=0;
			joystick.joy2_y2=0;
		}

			//main drive motor control
	if (!reversedControl) {
			motor[motorLeft] = (joystick.joy1_y1 + joystick.joy1_x2);
			motor[motorRight] = (joystick.joy1_y1 - joystick.joy1_x2);
		} else {
		motor[motorLeft] = -(joystick.joy1_y1 - joystick.joy1_x2);
			motor[motorRight] = -(joystick.joy1_y1 + joystick.joy1_x2);
		}
		if (joy1Btn(1)) {
			reversedControl = true;
		}
		if (joy1Btn(4)) {
			reversedControl = false;
		}
		}
		}
