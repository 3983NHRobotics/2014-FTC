//###################################################################################//
//
//								2013-2014 Autonomous Code
//							 Team 3983 - Highlands Robotics
//						  Code by T. Kluge & Music by J. Harnett
//
//###################################################################################//

void useOriginalAutonomous()
{
	TFileHandle irFileHandle;
	TFileIOResult IOResult;
	HTGYROstartCal(HTGYRO);
	PlaySound(soundBlip);
	//wait1Msec((2 * PI) * 1000); //TAUUUU
	//wait1Msec(10000);//wait 10 seconds for other teams who **might** have better autonomous code
	PlaySound(soundFastUpwardTones);

	//_________________________________BLOCK TO GET SENSORVALUES FROM IRSEEKER_________________________
	//=================================================================================================
	int _dirDCL = 0;
	int _dirACL = 0;
	int dcS1L, dcS2L, dcS3L, dcS4L, dcS5L = 0;
	int acS1L, acS2L, acS3L, acS4L, acS5L = 0;
	int _dirEnhL, _strEnhL;

	// the default DSP mode is 1200 Hz.

	initializeRobot();
	servo[servoLift]=123;
	servo[servoSweep]=199;
	waitForStart();
	ClearTimer(T1);
	OpenWrite(irFileHandle, IOResult, fileName, sizeOfFile);

	// FULLY DYNAMIC CODE W/ SCORING OF CUBE
	while(searching)
	{
		_dirDCL = HTIRS2readDCDir(HTIRS2L);
		if (_dirDCL < 0)
			break; // I2C read error occurred

		_dirACL = HTIRS2readACDir(HTIRS2L);
		if (_dirACL < 0)
			break; // I2C read error occurred

		//===========LEFT SIDE
		// Read the individual signal strengths of the internal sensors
		// Do this for both unmodulated (DC) and modulated signals (AC)
		if (!HTIRS2readAllDCStrength(HTIRS2L, dcS1L, dcS2L, dcS3L, dcS4L, dcS5L))
			break; // I2C read error occurred
		if (!HTIRS2readAllACStrength(HTIRS2L, acS1L, acS2L, acS3L, acS4L, acS5L ))
			break; // I2C read error occurred

		//=================Enhanced IR Values (Left and Right)===========
		// Read the Enhanced direction and strength
		if (!HTIRS2readEnhanced(HTIRS2L, _dirEnhL, _strEnhL))
			break; // I2C read error occurred

		//______________END SENSORVAL BLOCK________________________________________________________________
		//=================================================================================================

		if (acS3L < irFindVal) { //While sensor is heading towards beacon: acs3 = side
			motor[motorLeft] = -80;
			motor[motorRight] = -80;

			if (time1[T1] > timeToEnd) {
				searching = false;
				koth = true;
				goToEnd = false;
			}
		}

		//===================================BLOCK FOR IR DETECTION=====================
		if (acS3L > irFindVal) { //if sensor is directly in front of beacon

			if (time1[T1] < 2000) {
				wait1Msec(600);
			}

			motor[motorLeft] = 0;
			motor[motorRight] = 0;
			//irOnLeft = true;
			searching = false;
			koth = true;
			goToEnd = true;
		}

		//==================END IR DETECTION BLOCK========================

		wait1Msec(30);
	}//while searching

	//Close(irFileHandle, IOResult);
	roundTime = time1[T1]; //probably unnecessary, is to cut out the time from the cube scorer

	scoreCube();

	if (goToEnd) {
		driveToEnd(timeToEnd - roundTime);//drive to end of ramp
	}

	wait1Msec(300);

	//HTGYROstartCal(HTGYRO);
	ClearTimer(T3);

	while (true) {

		wait1Msec(20);

		//if (abs(rotSpeed) > 3) {
		rotSpeed = HTGYROreadRot(HTGYRO);//find gyro rotation speed
		heading += (rotSpeed * 0.02);//find gyro heading in degrees??

		motor[motorLeft] = 60;
		motor[motorRight] = -60;

		if (heading <= degFirstTurn) {

			int turnTime;
			turnTime = time1[T3] * 1000;
			motor[motorLeft] = 0;
			motor[motorRight] = 0;

			moveForward(3.2, 100);
			wait1Msec(200);

			while (true) {
				wait1Msec(20);
				rotSpeed = HTGYROreadRot(HTGYRO);//find gyro rotation speed
				heading += (rotSpeed * 0.02);//find gyro heading in degrees??

				motor[motorLeft] = 60;
				motor[motorRight] = -60;

				if (heading <= degSecondTurn) {
					motor[motorLeft] = 0;
					motor[motorRight] = 0;

					moveForward(3.3, 100);
					break;
				}
			}
			break;
		}
	}

	//wait1Msec(100);
	//turnRight(300, 100);

	//Begin KotH routine
	servo[servoUSSeeker] = 92;
	USScanVal = 92;
	float heading = 92;
	HTGYROstartCal(HTGYRO);

	while (koth) {

		//wait1Msec(1000);
		//SCAN LEFT==========================
		while(true) {

			servo[servoUSSeeker] = ServoValue[servoUSSeeker] + 5;
			USScanVal += 5;
			wait1Msec(100);

			if (SensorValue[US1] < kothAttackDistance && nPgmTime < 27000) { //if something is in range AND program time is less than 27 seconds
				PlaySound(soundFastUpwardTones);
				searchingForBot = true;
				turnedLeft = true;
				turnedRight = false;
				turnTowardsRobot();
				pushOffRamp();
				turnTowardsCenter();
			}
			if (USScanVal > 135) {
				break;
			}
		}
		//SCAN RIGHT=========================
		while(true) {
			servo[servoUSSeeker] = ServoValue[servoUSSeeker] - 5;
			USScanVal -= 5;
			wait1Msec(100);
			if (USScanVal < 40) {
				break;
			}
			if (SensorValue[US1] < kothAttackDistance && nPgmTime < 27000) { //if something is in range AND program time is less than 27 seconds
				PlaySound(soundFastUpwardTones);
				searchingForBot = true;
				turnedLeft = false;
				turnedRight = true;
				turnTowardsRobot();
				pushOffRamp();
				turnTowardsCenter();
			}
		}

		if (nPgmTime > 29000) {
			koth = false;
		}
	}//while koth
	PlaySound(soundDownwardTones);

}//task main
/*
//Define functions here instead of at the top
void driveToEnd(int distanceToEdge) {
	motor[motorLeft] = -80;
	motor[motorRight] = -80;
	wait1Msec(distanceToEdge);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;
}

void pushOffRamp() {
	moveForward(1.5, 100); //drive forward and backward (make sure this doesnt drive us off the ramp)
	wait1Msec(200);
	moveBackward(1.5, 100);
	wait1Msec(200);
	PlaySound(soundBlip);
}

void turnTowardsRobot() {
	//int tmpUS = USScanVal;
	time1[T2] = 0;

	while(searchingForBot) {
		while (USScanVal > 92 ) {

			wait1Msec(20);

			//if (abs(rotSpeed) > 3) {
			rotSpeed = HTGYROreadRot(HTGYRO);//find gyro rotation speed
			heading += (rotSpeed * 0.02) / 0.2;//find gyro heading in degrees??
			//}

			//PlayTone(400, 500);
			motor[motorLeft] = -5;
			motor[motorRight] = 5;
			if (heading >= USScanVal) {
				motor[motorLeft] = 0;
				motor[motorRight] = 0;
				searchingForBot = false;

			}//end if
			break;
		}//end while

		while (USScanVal < 92) {

			wait1Msec(20);

			//if (abs(rotSpeed) > 3) {
			rotSpeed = HTGYROreadRot(HTGYRO);//find gyro rotation speed
			heading += (rotSpeed * 0.02) / 0.3;//find gyro heading in degrees??
			//}

			//PlayTone(400, 500);
			motor[motorLeft] = 5;
			motor[motorRight] = -5;
			if (heading <= USScanVal) {
				motor[motorLeft] = 0;
				motor[motorRight] = 0;
				searchingForBot = false;

			}//end if
			break;
		}//end while

		if (USScanVal == 92) {
			//do nothing
			break;
		}
	}//end search
}//end void

void turnTowardsCenter() {

	if (turnedLeft) {
		while(heading > 92) {

			wait1Msec(20);

			//if (abs(rotSpeed) > 3) {
			rotSpeed = HTGYROreadRot(HTGYRO);//find gyro rotation speed
			heading += (rotSpeed * 0.02) / 0.2;//find gyro heading in degrees??
			//}

			motor[motorLeft] = 5;
			motor[motorRight] = -5;

			if (heading <= 92) {
				motor[motorLeft] = 0;
				motor[motorRight] = 0;
				break;
			}
		}
		turnedLeft = false;
		turnedRight = false;
	}

	if (turnedRight) {
		while(heading < 92) {

			wait1Msec(20);

			//if (abs(rotSpeed) > 3) {
			rotSpeed = HTGYROreadRot(HTGYRO);//find gyro rotation speed
			heading += (rotSpeed * 0.02) / 0.3;//find gyro heading in degrees??
			//}

			motor[motorLeft] = -5;
			motor[motorRight] = 5;

			if (heading >= 92) {
				motor[motorLeft] = 0;
				motor[motorRight] = 0;
				break;
			}
		}
		turnedLeft = false;
		turnedRight = false;
	}
}
*/