#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorRight,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorBelt,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorF2,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    srvoF1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    srvoF2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//####################################################################################//
//																																										//
//                                2014-2015 7005 TeleOp Code													//
//                         Teams 3983 and 7005 - Highlands Robotics										//
//                                    Code by T. Kluge																//
//																																										//
//####################################################################################//

// User Config ---------------
bool inDebug = true;
// End Config ----------------

#include "JoystickDriver.c"
//#include "../GlobalFunctions/debug.h"

bool canSloMo = true, sloMo = false, revDir = false, canRevDir = true;
int srvoVal[] = {0,50}; //add more stop positions as needed

task main() {
	nVolume = 3;
	waitForStart();
	while(true) {

		bFloatDuringInactiveMotorPWM = false;
		getJoystickSettings(joystick);

		if((joystick.joy1_y1 < 10 && joystick.joy1_y1 > -10) && (joystick.joy1_x1 < 10 && joystick.joy1_x1 > -10))
		{
			joystick.joy1_y1 = 0;
			joystick.joy1_x1 = 0;
		}
		if((joystick.joy1_x2 < 10 && joystick.joy1_x2 > -10) && (joystick.joy1_y2 < 10 && joystick.joy1_y2 > -10))
		{
			joystick.joy1_x2 = 0;
			joystick.joy1_y2 = 0;
		}

		/* uncomment following section for RC Car steering */
		/*if (!revDir) {
			if (!sloMo) {
				motor[motorLeft] = (joystick.joy1_y1 + joystick.joy1_x2);
				motor[motorRight] = (joystick.joy1_y1 - joystick.joy1_x2);
			} else {
				motor[motorLeft] = 0.16 * (joystick.joy1_y1 + joystick.joy1_x2);
				motor[motorRight] = 0.16 * (joystick.joy1_y1 - joystick.joy1_x2);
			}
		} else {
			if (!sloMo) {
				motor[motorLeft] = -(joystick.joy1_y1 + joystick.joy1_x2);
				motor[motorRight] = -(joystick.joy1_y1 - joystick.joy1_x2);
			} else {
				motor[motorLeft] = -0.16 * (joystick.joy1_y1 + joystick.joy1_x2);
				motor[motorRight] = -0.16 * (joystick.joy1_y1 - joystick.joy1_x2);
			}
		}*/

		/* uncomment following section for tank steering */
		if (!sloMo) {
			motor[motorLeft] = (joystick.joy1_y1);
			motor[motorRight] = (joystick.joy1_y2);
		} else {
			motor[motorLeft] = 0.16 * (joystick.joy1_y1);
			motor[motorRight] = 0.16 * (joystick.joy1_y2);
		}

		if (canSloMo) {
			if (!sloMo) {
				if (joy1Btn(12)) {
					sloMo = true;
					canSloMo = false;
					PlayImmediateTone(400, 10);
				}
			} else {
				if (joy1Btn(12)) {
					sloMo = false;
					canSloMo = false;
					PlayImmediateTone(600, 10);
				}
			}
		}
		if (!canSloMo) {
			if (!joy1Btn(12)) {
				canSloMo = true;
			}
		}
		if (canRevDir) {
			if (!revDir) {
				if (joy1Btn(11)) {
					revDir = true;
					canRevDir = false;
					PlayImmediateTone(300, 10);
				}
			} else {
				if (joy1Btn(11)) {
					revDir = false;
					canRevDir = false;
					PlayImmediateTone(800, 10);
				}
			}
		}
		if (!canRevDir) {
			if (!joy1Btn(11)) {
				canRevDir = true;
			}
		}

		// -------------------------------	End Drive Code	-------------------------------
		if (joy2Btn(5)) {
			motor[motorLift] = 100;
		} else if (joy2Btn(7)) {
			motor[motorLift] = -100;
		} else {
			motor[motorLift] = 0;
		}

		if (joystick.joy2_TopHat == 0)
			motor[motorBelt] = 100;
		else if (joystick.joy2_TopHat == 4)
			motor[motorBelt] = -100;
		else
			motor[motorBelt] = 0;

		if (joy2Btn(6)) {
			servo[srvoF1] = srvoVal[0];
			servo[srvoF2] = srvoVal[0];
		}
		if (joy2Btn(8)) {
			servo[srvoF1] = srvoVal[1];
			servo[srvoF2] = srvoVal[1];
		}
	} //while true
} //task main
