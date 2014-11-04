#2014 TeleOp & Autonomous code for FTC Cascade Effect Challenge
##### [View repository on github](https://github.com/3983NHRobotics/2014-FTC)
<!--- make this h1 thing a link to the github repo - it will serve as the link to here from the highlandsrobo site --->

<hr id="teleop">
<!--- I needed the id --->

##Tele0p

###Test:
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

<hr id="autonomous">

##Autonomous

> Autonomous wheeeeee
