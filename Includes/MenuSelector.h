//####################################################################################//
//																																										//
//                                 2014-2015 Selector Code														//
//                         Teams 3983 and 7005 - Highlands Robotics										//
//                                    Code by T. Kluge																//
//																																										//
//####################################################################################//

string menuFirst = "Auton Chooser";
string placeholder = "PlacHold";
string prog[] = {
				 "Auton_01",
				 "Auton_02",
				 "ClearStr",
				 "PlacHold",
				 "PlacHold",
				 "PlacHold"
				 };

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
	nxtDisplayTextLine (2, "%s <", prog[0]);
	nxtDisplayTextLine (3, "%s", prog[1]);
	nxtDisplayTextLine (4, "%s", prog[2]);
	nxtDisplayTextLine (5, "%s", prog[3]);
	nxtDisplayTextLine (6, "%s", prog[4]);
	//drawArrow_1();

}

void updateSelSecond() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[0]);
	nxtDisplayTextLine (3, "%s <", prog[1]);
	nxtDisplayTextLine (4, "%s", prog[2]);
	nxtDisplayTextLine (5, "%s", prog[3]);
	nxtDisplayTextLine (6, "%s", prog[4]);
	//drawArrow_2();

}
void updateSelThird() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[0]);
	nxtDisplayTextLine (3, "%s", prog[1]);
	nxtDisplayTextLine (4, "%s <", prog[2]);
	nxtDisplayTextLine (5, "%s", prog[3]);
	nxtDisplayTextLine (6, "%s", prog[4]);
	//drawArrow_3();

}
void updateSelFourth() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[0]);
	nxtDisplayTextLine (3, "%s", prog[1]);
	nxtDisplayTextLine (4, "%s", prog[2]);
	nxtDisplayTextLine (5, "%s <", prog[3]);
	nxtDisplayTextLine (6, "%s", prog[4]);
	//drawArrow_4();

}
void updateSelFifth() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[0]);
	nxtDisplayTextLine (3, "%s", prog[1]);
	nxtDisplayTextLine (4, "%s", prog[2]);
	nxtDisplayTextLine (5, "%s", prog[3]);
	nxtDisplayTextLine (6, "%s <", prog[4]);
	//drawArrow_5();

}
void updateSelSixth() {
	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s <", prog[5]);
	nxtDisplayTextLine (3, "%s", placeholder);
	nxtDisplayTextLine (4, "%s", placeholder);
	nxtDisplayTextLine (5, "%s", placeholder);
	nxtDisplayTextLine (6, "%s", placeholder);

}
void runSelectedPgm() {
	//set all control variables in this function to tell the robot what to do in autonomous.
	//This just makes it a bit easier so that we dont have to use numbers to refer to the code conditions
	PROGID = selectedProgram;
}
