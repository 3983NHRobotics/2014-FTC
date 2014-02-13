#include "../GlobalFunctions/GlobalFunctions.c"

void useDummyAutonomous() {
	waitForStart();

	//while(running) {
	//servo[servoSweep] = 0;
	//servo[servoLift] = 0;

	//armClamp();//close bucket

	moveForward(2.5, 100);

	//armLift(3, 100);//lift arm
	wait1Msec(300);

	turnRight(1, 100);//turn towards ramp

	wait1Msec(300);

	moveForward(2.7, 100);//drive onto ramp
	//should be on the ramp now
	//turnLeft(1, 100);//turn away from basket

	//armLift(2, 100);//lift arm to basket

	//armUnClamp();//drop blocks

  MissionImpossible();
}
