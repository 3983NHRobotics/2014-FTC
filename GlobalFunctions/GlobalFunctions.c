//This is a file for functions that are good for everything ever
/*
* void moveForward(int mtime, int mpower);
* void moveBackward(int mtime, int mpower);
* void turnLeft(int mtime, int mpower);
* void turnRight(int mtime, int mpower);
*/


void moveForward(int mtime, int mpower) {

	motor[motorLeft] = -1 *mpower;
	motor[motorRight] = -1 * mpower;
	wait1Msec(mtime * 1000);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;

}

void moveBackward(int mtime, int mpower) {

	motor[motorLeft] = mpower;
	motor[motorRight] = mpower;
	wait1Msec(mtime * 1000);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;

}

void turnLeft(int mtime, int mpower) {

	motor[motorLeft] = mpower;
	motor[motorRight] = -1 * mpower;
	wait1Msec(mtime);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;

}

void turnRight(int mtime, int mpower) {

	motor[motorLeft] = -1 * mpower;
	motor[motorRight] = mpower;
	wait1Msec(mtime);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;

}