#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorFrontLeft,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorFrontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorBackLeft,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorBackRight, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorSpinner,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorLauncher,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servoLeft,            tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servoRight,           tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//####################################################################################//
//																																										//
//                                 2014-2015 TeleOp Code															//
//                         Teams 3983 and 7005 - Highlands Robotics										//
//                                    Code by T. Kluge																//
//																																										//
//####################################################################################//

// User Config ---------------
bool inDebug = true;
// End Config ----------------

#include "JoystickDriver.c"
#include "GlobalFunctions/OmniwheelFunctions.h"

bool sloMo = false;

int servoVal_left_up = 135,
		servoVal_left_down = 0;
int servoVal_right_up = 109,
		servoVal_right_down = 240;

task main() {

//Initialize servos
servo[srvo_S1_C3_1] = servoVal_left_up;
servo[srvo_S1_C3_2] = servoVal_right_up;
//end init
	waitForStart();
	while(true) {

		bFloatDuringInactiveMotorPWM = false;
		getJoystickSettings(joystick);

		//CONTROLLER 1 JOYSTICK 1
		if((joystick.joy1_y1 < 10 && joystick.joy1_y1 > -10) && (joystick.joy1_x1 < 10 && joystick.joy1_x1 > -10))
		{
			joystick.joy1_y1 = 0;
			joystick.joy1_x1 = 0;
		}
		//CONTROLLER 1 JOYSTICK 2
		if((joystick.joy1_x2 < 10 && joystick.joy1_x2 > -10) && (joystick.joy1_y2 < 10 && joystick.joy1_y2 > -10))
		{
			joystick.joy1_x2 = 0;
			joystick.joy1_y2 = 0;
		}

		if (!sloMo) {
			motor[motorFrontLeft] = (-1 * joystick.joy1_y1) + (-1 * joystick.joy1_x1) + (-1 * joystick.joy1_x2);
			motor[motorFrontRight] = (joystick.joy1_y1) + (-1 * joystick.joy1_x1) + (-1 * joystick.joy1_x2);
			motor[motorBackRight] = (joystick.joy1_y1) + (joystick.joy1_x1) + (-1 * joystick.joy1_x2);
			motor[motorBackLeft] = (-1 * joystick.joy1_y1) + (joystick.joy1_x1) + (-1 * joystick.joy1_x2);
		} else {
			motor[motorFrontLeft] = 0.16 * ((-1 * joystick.joy1_y1) + (-1 * joystick.joy1_x1) + (-1 * joystick.joy1_x2));
			motor[motorFrontRight] = 0.16 * ((joystick.joy1_y1) + (-1 * joystick.joy1_x1) + (-1 * joystick.joy1_x2));
			motor[motorBackRight] = 0.16 * ((joystick.joy1_y1) + (joystick.joy1_x1) + (-1 * joystick.joy1_x2));
			motor[motorBackLeft] = 0.16 * ((-1 * joystick.joy1_y1) + (joystick.joy1_x1) + (-1 * joystick.joy1_x2));
		}

		if (!joy1Btn(12)) { //see if this actually works
			if (!sloMo) {
				if (joy1Btn(12)) {
					sloMo = true;
				}
				} else {
				if (joy1Btn(12)) {
					sloMo = false;
				}
			}
		}
		// -------------------------------	End Drive Code	-------------------------------
		if (joy2Btn(1)) {
			motor[motorLauncher] = -100;
		} else if (joy2Btn(4)) {
			motor[motorLauncher] = 100;
		} else {
			motor[motorLauncher] = 0;
		}

		if (joy2Btn(2))
			motor[motorSpinner] = -100;
		else if (joy2Btn(3))
			motor[motorSpinner] = 100;
		else
			motor[motorSpinner] = 0;

		if (joy2Btn(6)) {
			//servo[servoLeft] = servoVal_open;
			servo[srvo_S1_C3_1] = servoVal_left_up;
			servo[srvo_S1_C3_2] = servoVal_right_up;
		}
		if (joy2Btn(8)) {
			servo[srvo_S1_C3_1] = servoVal_left_down;
			servo[srvo_S1_C3_2] = servoVal_right_down;
		}
	} //while true
} //task main
