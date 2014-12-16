#2014 TeleOp & Autonomous code for FTC Cascade Effect Challenge
##### [View repository on github](https://github.com/3983NHRobotics/2014-FTC)
<!--- make this h1 thing a link to the github repo - it will serve as the link to here from the highlandsrobo site --->

<hr id="teleop">
<!--- I needed the id --->

##Tele0p

The teleop code for this robot went from being a tank drive type robot to an omnidirectional platform capable of moving in all 4 directions as well as spinning in place. Controller 1 controls the robot's movement - left joystick controls straight motion, right joystick controls the rotation. Controller 2 is in charge of all of the other motors and servos on the robot. Both controllers will have the ability to use any sweeper mechanish on the robot, because it can be easier for one person to coordinate the sweeping with the movement of the robot.

Controller 1 can press the right joystick to toggle slomo mode, where the drive motors run at 16% power so that the robot is easier to control.


<hr id="autonomous">

##Autonomous

This year's autonomous is finished, but entirely untested. This is because the actual robot has been taken apart and reassembled 3 times. It is simplified from last year's, using more methods instead of writing out stuff many times.

```
task main() {

	StartTask(getHeading); ///start the compass loop
	StartTask(getIR); //start the IR loop

	waitForStart();

	moveForward(1500, 100);
	turnDeg("right", 120, 100);

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
```
