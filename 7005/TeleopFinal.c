#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorBelt,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorSweeper,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorUndef,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "joystickdriver.c"

int bucketOpenVal = 110;
int bucketCloseVal = 12;

task main()
 {
	PlaySound(soundBeepBeep);
	waitForStart();
	PlaySound(soundUpwardTones);
	while(true)
	{

		bFloatDuringInactiveMotorPWM = false;
		getJoystickSettings(joystick);
		//Prevents random movement on the y axis
		if(joystick.joy1_y1 < 10 && joystick.joy1_y1 > -10) {
			joystick.joy1_y1 = 0;
		}
		//Prevents random movement on the x axis
		if(joystick.joy1_x2 < -10 && joystick.joy1_x2 > 10) {
			joystick.joy1_x2 = 0;
		}

		//Drive Control
		motor[motorLeft] = (joystick.joy1_y1);
		motor[motorRight] = (joystick.joy1_y2);

		if(joy1Btn(7) || joy2Btn(7)) {
			motor[motorSweeper] = 70;
			} else if (joy1Btn(5) || joy2Btn(5)) {
			motor[motorSweeper] = -70;
			} else {
			motor[motorSweeper] = 0;
		}

		if (joy2Btn(8)) {
				motor[motorBelt] = 100;
				} else if (joy2Btn(6)) {
				motor[motorBelt] = -100;
				} else {
				motor[motorBelt] = 0;
			}

		if(joy2Btn(4)) {
				motor[motorLift] = 100;
				} else if (joy2Btn(1)) {
				motor[motorLift] = -100;
				} else {
				motor[motorLift] = 0;
			}

		if (joy2Btn(2)) {
				servo[servo1] = bucketOpenVal;
				}
		if (joy2Btn(3)) {
				servo[servo1] = bucketCloseVal;
				}

	}//end of while loop
}//end of task
