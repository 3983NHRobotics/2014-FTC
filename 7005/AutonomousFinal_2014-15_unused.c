#pragma config(Hubs,  S3, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S3_C1_1,     motorLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     motorLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_1,     motorRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     motorUndef1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C3_1,     motorSweep,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C3_2,     motorLeft,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S3_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S3_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S3_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "joystickdriver.c"
task main() {

	PlaySound(soundBeepBeep);
	waitForStart();
	PlaySound(soundUpwardTones);

	motor[motorLeft] = 100;
	motor[motorRight] = 100;
	wait1Msec(3000);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;

}