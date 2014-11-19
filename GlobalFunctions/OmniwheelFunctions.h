//This is a file for functions that are good for everything ever for omniwheels

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
	motor[motorFrontLeft] = -1 * mpower;
	motor[motorFrontRight] = mpower;
	motor[motorBackRight] = mpower;
	motor[motorBackLeft] = -1 * mpower;
	wait1Msec(mtime);
	motor[motorFrontLeft] = 0;
	motor[motorFrontRight] = 0;
	motor[motorBackRight] = 0;
	motor[motorBackLeft] = 0;
}

void moveBackward(int mtime, int mpower) {
	motor[motorFrontLeft] = mpower;
	motor[motorFrontRight] = -1 * mpower;
	motor[motorBackRight] = -1 * mpower;
	motor[motorBackLeft] = mpower;
	wait1Msec(mtime);
	motor[motorFrontLeft] = 0;
	motor[motorFrontRight] = 0;
	motor[motorBackRight] = 0;
	motor[motorBackLeft] = 0;
}

void moveForwardConst(int mpower) {
	motor[motorFrontLeft] = -1 * mpower;
	motor[motorFrontRight] = mpower;
	motor[motorBackRight] = mpower;
	motor[motorBackLeft] = -1 * mpower;
}

void moveBackwardConst(int mpower) {
	motor[motorFrontLeft] = mpower;
	motor[motorFrontRight] = -1 * mpower;
	motor[motorBackRight] = -1 * mpower;
	motor[motorBackLeft] = mpower;
}

void turnLeft(int mtime, int mpower) {
	motor[motorFrontLeft] = mpower;
	motor[motorFrontRight] = mpower;
	motor[motorBackRight] = mpower;
	motor[motorBackLeft] = mpower;
	wait1Msec(mtime);
	motor[motorFrontLeft] = 0;
	motor[motorFrontRight] = 0;
	motor[motorBackRight] = 0;
	motor[motorBackLeft] = 0;
}

void turnRight(int mtime, int mpower) {
	motor[motorFrontLeft] = -1 * mpower;
	motor[motorFrontRight] = -1 * mpower;
	motor[motorBackRight] = -1 * mpower;
	motor[motorBackLeft] = -1 * mpower;
	wait1Msec(mtime);
	motor[motorFrontLeft] = 0;
	motor[motorFrontRight] = 0;
	motor[motorBackRight] = 0;
	motor[motorBackLeft] = 0;
}

void turnLeftCont(int mpower) {
	motor[motorFrontLeft] = mpower;
	motor[motorFrontRight] = mpower;
	motor[motorBackRight] = mpower;
	motor[motorBackLeft] = mpower;
}

void turnRightCont(int mpower) {
	motor[motorFrontLeft] = -1 * mpower;
	motor[motorFrontRight] = -1 * mpower;
	motor[motorBackRight] = -1 * mpower;
	motor[motorBackLeft] = -1 * mpower;
}

void stopMotors() {
	motor[motorFrontLeft] = 0;
	motor[motorFrontRight] = 0;
	motor[motorBackRight] = 0;
	motor[motorBackLeft] = 0;
}
