#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S2,     GYRO,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     HTIRS2,         sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorFrontLeft, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorFrontRight, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorBackLeft, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorBackRight, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorSpinner,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorLauncher, tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servoLeft,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servoRight,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//####################################################################################//
//																																										//
//                             2014-2015 Smart Autonomous Code												//
//                         Teams 3983 and 7005 - Highlands Robotics										//
//                                    Code by T. Kluge																//
//																																										//
//####################################################################################//

// User Config ---------------
bool inDebug = true;
// End Config ----------------

#include "../drivers/JoystickDriver_CustomNoSplash.c"
#include "../Includes/MenuSelector.h"
#include "../GlobalFunctions/OmniwheelFunctions.h"
#include "../Drivers/hitechnic-sensormux.h"
#include "../Drivers/lego-light.h"
#include "../Drivers/hitechnic-irseeker-v2.h"
#include "../Drivers/hitechnic-gyro.h"

//variable initialization

int counter = 0;
int curHeading = 0, h = 0; //try to get this from -360 to +360
int light = 50;
			int legoLS = 0; //set to const tMuxSensor LEGOLS = M1_S2 or whatever
			int irPeak = 200; //set to tMuxSensor IRVAL or something
bool beaconIsFound = false;


//function initialization

void turnDeg(const string dir, int deg, int power);
void turnTime(const string dir, int time, int power);
void resetHeading();
void searchForLine(int power);
//int getHeading();
bool irExists;

//get robot directional info task

task getHeading() {
	float delTime = 0;
	float prevHeading = 0;
	float curRate = 0;

  HTGYROstartCal(GYRO);
  PlaySound(soundBeepBeep);
  while (true) {
    time1[T1] = 0;
    curRate = HTGYROreadRot(GYRO);
    if (abs(curRate) > 3) {
      prevHeading = curHeading;
      curHeading = prevHeading + curRate * delTime;
      if (curHeading > 360) curHeading -= 360;
      else if (curHeading < 0) curHeading += 360;
    }
    wait1Msec(5);
    delTime = ((float)time1[T1]) / 1000;
    //delTime /= 1000;
  }
}

//get robot IRsensor info task

task getIR() {
	int _dirDC = 0;
	int _dirAC = 0;
	int dcS1, dcS2, dcS3, dcS4, dcS5 = 0;
	int acS1, acS2, acS3, acS4, acS5 = 0;
	int _dirEnh, _strEnh;
	int irVal = 0;

	while (true) {
		_dirDC = HTIRS2readDCDir(HTIRS2);
		if (_dirDC < 0) {
			break; // I2C read error occurred
		}
		_dirAC = HTIRS2readACDir(HTIRS2);
		if (_dirAC < 0) {
			break; // I2C read error occurred
		}

		if (!HTIRS2readAllDCStrength(HTIRS2, dcS1, dcS2, dcS3, dcS4, dcS5)) {
			break; // I2C read error occurred
		}
		if (!HTIRS2readAllACStrength(HTIRS2, acS1, acS2, acS3, acS4, acS5 )) {
			break; // I2C read error occurred
		}
		// Read the Enhanced direction and strength
		if (!HTIRS2readEnhanced(HTIRS2, _dirEnh, _strEnh)) {
			break; // I2C read error occurred
		}
		//set understandable values
		irVal = acS3; //directly in front of the sensor

		if (irVal > irPeak) {
			irExists = true;
		} else {
			irExists = false;
		}
	}
}

//Main Program

task main() {

	StartTask(getHeading); ///start the compass loop
	StartTask(getIR); //start the IR loop

	waitForStart();

	moveForward(3000, 100); //move forward off ramp
	turnDeg("left", 90, 100); //turn left towards center of field
	moveForward(1500, 100); //move towards center of field
	turnDeg("right", 120, 100); //turn 120deg right to align with hexagon in center

	do {
		searchForLine(1000); //move forward until it finds a line on the ground
		turnDeg("left", 120, 100); //turn left 120deg (because the base is a hexagon and it needs to check 3 sides)
		if (irExists) { //if it sees a beacon after turning,
			beaconIsFound = true; //end the search loop.
		}
		counter++; //add 1 to counter because it only needs to check 3 sides (there are 2 beacons)
	} while (!beaconIsFound && counter < 3);

	//knock_stand_down()

} //end task main

void turnDeg(const string dir, int deg, int power) {
	//debug("Turning %d", deg);

	resetHeading();
	//when told to turn, turn until robot is facing correct direction
	if (dir == "left") {
		do { //these could probably be normal while loops
			turnLeftCont(power);
		} while (curHeading > deg);
	} else if (dir == "right") {
		do {
			turnRightCont(power);
		} while (curHeading <= deg);
	} else {
		//debug("Got invalid direction: ", dir);
	}
	//when facing right way, stop turning.
	stopMotors();
}

void turnTime(const string dir, int time, int power) {
	//debug("Turning %d", time/1000);

	if (dir == "left") {
		turnLeftCont(power);
		wait1Msec(time);
		stopMotors();
	} else if (dir == "right") {
		turnRightCont(power);
		wait1Msec(time);
		stopMotors();
	} else {
		//debug("Got invalid direction: ", dir);
	}
}

void resetHeading() {
	h = 0;
	curHeading = 0;
}

void searchForLine(int power) {
	do { //this could also be a normal while loop
		moveForwardConst(power);
	} while (legoLS < light);
	stopMotors();
}
