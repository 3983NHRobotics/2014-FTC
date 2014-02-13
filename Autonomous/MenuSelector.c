//###################################################################################//
//
//							2013-2014 Program Selector Code
//							 Team 3983 - Highlands Robotics
//						        	Code by T. Kluge
//
//###################################################################################//

//#include "Auton_ALL.c";

string menuFirst = "AutCh";
string placeholder = "PlacHold";
string progFirst = "fw-fw-L1";
string progSecond = "fw-fw-L2";
string progThird = "fw-bw-L1";
string progFourth = "fw-bw-L2";
string progFifth = "AutonDUM";
string progSixth = "DoNotUse";

int totalChoices = 6;
int selectionValue = 1;
int selectedProgram = -1;
int PROGID;

bool progSelected = false;

void updateDisplay();
void updateSelFirst();
void updateSelSecond();
void updateSelThird();
void updateSelFourth();
void updateSelFifth();
void updateSelSixth();
void runSelectedPgm();

//#include "../drivers/JoystickDriver_CustomNoSplash.c"

void chooseProgram() {

	//Initialize the display with the program choices
	disableDiagnosticsDisplay();
	updateSelFirst();

	wait1Msec(50);

	while (!progSelected) {
		//Right arrow
		switch (nNxtButtonPressed) {
			case 1:
				PlaySoundFile("! Click.rso");
				eraseDisplay();
				selectionValue++;
				updateDisplay();
				wait1Msec(300);
				break;
			case 2:
				PlaySoundFile("! Click.rso");
				eraseDisplay();
				selectionValue--;
				updateDisplay();
				wait1Msec(300);
				break;
			case 3:
				PlaySoundFile("! Attention.rso");
				eraseDisplay();
				enableDiagnosticsDisplay();
				selectedProgram = selectionValue;
				runSelectedPgm();
				progSelected = true;
				break;
		}
		if (selectionValue > totalChoices) {
			selectionValue = 1;
			eraseDisplay();
			updateDisplay();
		}
		if (selectionValue <= 0) {
			selectionValue = totalChoices;
			eraseDisplay();
			updateDisplay();
		}
	}
}

void updateDisplay() {
	switch (selectionValue) {
		case 1:
			updateSelFirst();
			break;
		case 2:
			updateSelSecond();
			break;
		case 3:
			updateSelThird();
			break;
		case 4:
			updateSelFourth();
			break;
		case 5:
			updateSelFifth();
			break;
		case 6:
			updateSelSixth();
			break;
	}
}

void updateSelFirst() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s <", progFirst);
	nxtDisplayTextLine (3, "%s", progSecond);
	nxtDisplayTextLine (4, "%s", progThird);
	nxtDisplayTextLine (5, "%s", progFourth);
	nxtDisplayTextLine (6, "%s", progFifth);
	drawArrow_1();

}

void updateSelSecond() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", progFirst);
	nxtDisplayTextLine (3, "%s <", progSecond);
	nxtDisplayTextLine (4, "%s", progThird);
	nxtDisplayTextLine (5, "%s", progFourth);
	nxtDisplayTextLine (6, "%s", progFifth);
	drawArrow_2();

}
void updateSelThird() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", progFirst);
	nxtDisplayTextLine (3, "%s", progSecond);
	nxtDisplayTextLine (4, "%s <", progThird);
	nxtDisplayTextLine (5, "%s", progFourth);
	nxtDisplayTextLine (6, "%s", progFifth);
	drawArrow_3();

}
void updateSelFourth() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", progFirst);
	nxtDisplayTextLine (3, "%s", progSecond);
	nxtDisplayTextLine (4, "%s", progThird);
	nxtDisplayTextLine (5, "%s <", progFourth);
	nxtDisplayTextLine (6, "%s", progFifth);
	drawArrow_4();

}
void updateSelFifth() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", progFirst);
	nxtDisplayTextLine (3, "%s", progSecond);
	nxtDisplayTextLine (4, "%s", progThird);
	nxtDisplayTextLine (5, "%s", progFourth);
	nxtDisplayTextLine (6, "%s <", progFifth);
	//drawArrow_5();

}
void updateSelSixth() {
	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s <", progSixth);
	nxtDisplayTextLine (3, "%s", placeholder);
	nxtDisplayTextLine (4, "%s", placeholder);
	nxtDisplayTextLine (5, "%s", placeholder);
	nxtDisplayTextLine (6, "%s", placeholder);

}
void runSelectedPgm() {
	//set all control variables in this function to tell the robot what to do in autonomous.
	//This just makes it a bit easier so that we dont have to use numbers to refer to the code conditions

	switch (selectedProgram) {
		case 1:
			PROGID = 1;
			break;
		case 2:
			PROGID = 2;
			break;
		case 3:
			PROGID = 3;
			break;
		case 4:
			PROGID = 4;
			break;
		case 5:
			PROGID = 5;
			break;
		case 6:
			PROGID = 6;
			progSelected = false;
			break;
	}
}
