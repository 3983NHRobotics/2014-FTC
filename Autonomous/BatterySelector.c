//###################################################################################//
//
//							2013-2014 Battery Level Selector Code
//							 Team 3983 - Highlands Robotics
//						        	Code by T. Kluge
//
//###################################################################################//

void updateBatFirst();
void updateBatSecond();
void updateBatThird();
void updateBatFourth();
void updateBatFifth();
void setBatPower();
void updateDisplayBat();
void setBatLevel();

string batInt_1 = "100";
string batInt_2 = "90";
string batInt_3 = "80";
string batInt_4 = "70";
string batInt_5 = "60";

bool batSelected = false;
int BATVAL;
int selectedBat = -1;
int batValue = 1;
int totalBatChoices = 5;

void setBatPower() {
	updateBatFirst();

	wait1Msec(50);

	while (!batSelected) {
		//Right arrow
		switch (nNxtButtonPressed) {
			case 1:
				PlaySoundFile("! Click.rso");
				eraseDisplay();
				batValue++;
				updateDisplayBat();
				wait1Msec(300);
				break;
			case 2:
				PlaySoundFile("! Click.rso");
				eraseDisplay();
				batValue--;
				updateDisplayBat();
				wait1Msec(300);
				break;
			case 3:
				PlaySoundFile("! Attention.rso");
				eraseDisplay();
				selectedBat = batValue;
				setBatLevel();
				batSelected = true;
				break;
		}
		if (batValue > totalBatChoices) {
			batValue = 1;
			eraseDisplay();
			updateDisplayBat();
		}
		if (batValue <= 0) {
			batValue = totalBatChoices;
			eraseDisplay();
			updateDisplayBat();
		}
	}
}

void updateDisplayBat() {
	switch (batValue) {
		case 1:
			updateBatFirst();
			break;
		case 2:
			updateBatSecond();
			break;
		case 3:
			updateBatThird();
			break;
		case 4:
			updateBatFourth();
			break;
		case 5:
			updateBatFifth();
			break;
	}
}

void updateBatFirst() {

	nxtDisplayCenteredTextLine (1, "%s", "Battery Level");
	nxtDisplayTextLine (2, "100 <");
	nxtDisplayTextLine (3, "90");
	nxtDisplayTextLine (4, "80");
	nxtDisplayTextLine (5, "70");
	nxtDisplayTextLine (6, "60");
	//drawBattery_1();

}

void updateBatSecond() {

	nxtDisplayCenteredTextLine (1, "%s", "Battery Level");
	nxtDisplayTextLine (2, "100");
	nxtDisplayTextLine (3, "90 <");
	nxtDisplayTextLine (4, "80");
	nxtDisplayTextLine (5, "70");
	nxtDisplayTextLine (6, "60");
	//drawBattery_2();

}

void updateBatThird() {

	nxtDisplayCenteredTextLine (1, "%s", "Battery Level");
	nxtDisplayTextLine (2, "100");
	nxtDisplayTextLine (3, "90");
	nxtDisplayTextLine (4, "80 <");
	nxtDisplayTextLine (5, "70");
	nxtDisplayTextLine (6, "60");
	//drawBattery_3();

}

void updateBatFourth() {

	nxtDisplayCenteredTextLine (1, "%s", "Battery Level");
	nxtDisplayTextLine (2, "100");
	nxtDisplayTextLine (3, "90");
	nxtDisplayTextLine (4, "80");
	nxtDisplayTextLine (5, "70 <");
	nxtDisplayTextLine (6, "60");
	//drawBattery_4();

}

void updateBatFifth() {

	nxtDisplayCenteredTextLine (1, "%s", "Battery Level");
	nxtDisplayTextLine (2, "100");
	nxtDisplayTextLine (3, "90");
	nxtDisplayTextLine (4, "80");
	nxtDisplayTextLine (5, "70");
	nxtDisplayTextLine (6, "60 <");
	//drawBattery_5();

}

void setBatLevel() {
	//set all control variables in this function to tell the robot what to do in autonomous.
	//This just makes it a bit easier so that we dont have to use numbers to refer to the code conditions

	switch (selectedBat) {
		case 1:
			BATVAL = 100;
			break;
		case 2:
			BATVAL = 90;
			break;
		case 3:
			BATVAL = 80;
			break;
		case 4:
			BATVAL = 70;
			break;
		case 5:
			BATVAL = 60;
			break;
	}
}
