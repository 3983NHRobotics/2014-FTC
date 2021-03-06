#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorLeft,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorBelt,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorUnused,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorLift2,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    srvoF1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    srvoF2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
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
int tone = 500;
int ff[] = {490, 613, 640, 750, 640, 750};
#include "Drivers/JoystickDriver_CustomNoSplash.c"
//#include "../GlobalFunctions/debug.h"
task main() {
	nVolume = 3;
	PlayImmediateTone(500, 40);
	waitForStart();
	PlayImmediateTone(750, 40);
		disableDiagnosticsDisplay();
		eraseDisplay();
	while(true) {
		bFloatDuringInactiveMotorPWM = false;
		getJoystickSettings(joystick);

		PlayTone(tone, 10);
		if (joy1Btn(1)) {
			tone += 10;
			wait1Msec(100);
		}

		if (joy1Btn(3)) {
			tone -= 10;
			wait1Msec(100);
		}

		if (joy1Btn(2)) {
			ClearSounds();
			PlayImmediateTone(ff[0], 10);
			PlayImmediateTone(ff[1], 10);
			PlayImmediateTone(ff[2], 10);
			PlayImmediateTone(ff[3], 20);
			PlayImmediateTone(ff[4], 10);
			PlayImmediateTone(ff[5], 40);
		}

		nxtDisplayCenteredTextLine(2, "Hz: %d", tone);
		wait1Msec(100);
	} //while true
} //task main
