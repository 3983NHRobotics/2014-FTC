//This is a file for functions that are good for everything ever

void moveForward(int mtime, int mpower);
void moveBackward(int mtime, int mpower);
void moveForwardConst(int mpower);
void moveBackwardConst(int mpower);
void turnLeft(int mtime, int mpower);
void turnRight(int mtime, int mpower);
void turnLeftCont(int mpower);
void turnRightCont(int mpower);
void stopMotors();

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

void moveForwardConst(int mpower) {
	motor[motorLeft] = -1 *mpower;
	motor[motorRight] = -1 * mpower;
}

void moveBackwardConst(int mpower) {
	motor[motorLeft] = mpower;
	motor[motorRight] = mpower;
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

void turnLeftCont(int mpower) {
	motor[motorLeft] = mpower;
	motor[motorRight] = -1 * mpower;
}

void turnRightCont(int mpower) {
	motor[motorLeft] = -1 * mpower;
	motor[motorRight] = mpower;
}

void stopMotors() {
	motor[motorLeft] = 0;
	motor[motorRight] = 0;
}
