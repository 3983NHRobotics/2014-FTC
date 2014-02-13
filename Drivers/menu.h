#if 0
/// Copyright (c) Titan Robotics Club. All rights reserved.
///
/// <module name="menu.h" />
///
/// <summary>
///     This module contains the library functions for displaying a choice
///     menu on the NXT LCD screen and read the user choice input from the
///     NXT buttons.
/// </summary>
///
/// <remarks>
///     Environment: RobotC for Lego Mindstorms NXT.
/// </remarks>
#endif

#ifndef _MENU_H
#define _MENU_H

#pragma systemFile

#ifdef MOD_ID
    #undef MOD_ID
#endif
#define MOD_ID                  MOD_MENU

//
// Constants
//
#define MAX_NUM_CHOICES         6

//
// Type definitions.
//
typedef struct
{
    string titleText;
    int    startLine;
    int    userChoice;
    string choices[MAX_NUM_CHOICES];
    int    numChoices;
} MENU;

/**
 *  This function initializes the choice menu.
 *
 *  @param menu Points to the MENU structure to be initialized.
 *  @param titleText Specifies the title text of the menu.
 *  @param startLine Specifies the LCD line the menu starts.
 *  @param defChoice Specifies the default choice.
 */
void
MenuInit(
    __out MENU &menu,
    __in  string titleText,
    __in  int startLine,
    __in  int defChoice
    )
{
    TFuncName("MenuInit");
    TLevel(INIT);
    TEnter();

    strcpy(menu.titleText, titleText);
    menu.startLine = startLine;
    menu.userChoice = defChoice;
    menu.numChoices = 0;

    TExit();
    return;
}   //MenuInit

/**
 *  This function adds a choice to the menu.
 *
 *  @param menu Points to the MENU structure to be initialized.
 *  @param choiceText Specifies the choice text.
 *
 *  @return Returns true if the choice is added successful, otherwise the
 *          menu is full.
 */
bool
MenuAddChoice(
    __inout MENU &menu,
    __in    string choiceText
    )
{
    bool fSuccess = false;

    TFuncName("MenuAddChoice");
    TLevel(API);
    TEnter();

    if (menu.numChoices < MAX_NUM_CHOICES)
    {
        strcpy(menu.choices[menu.numChoices], choiceText);
        menu.numChoices++;
        fSuccess = true;
    }

    TExit();
    return fSuccess;
}   //MenuAddChoice

/**
 *  This function displays the menu and returns the user choice.
 *
 *  @param menu Points to the MENU structure to be initialized.
 *
 *  @return Returns the user choice.
 */
int
MenuGetChoice(
    __inout MENU &menu
    )
{
    int choice;
    TButtons prevNxtBtn;
    TButtons currNxtBtn;

    TFuncName("MenuGetChoice");
    TLevel(API);
    TEnter();

    eraseDisplay();
    nxtDisplayTextLine(menu.startLine, menu.titleText);
    for (choice = 0; choice < menu.numChoices; choice++)
    {
        nxtDisplayTextLine(menu.startLine + 1 + choice,
                           "%d: %s", choice, menu.choices[choice]);
    }

    prevNxtBtn = nNxtButtonPressed;
    while (true)
    {
        currNxtBtn = nNxtButtonPressed;
        if (currNxtBtn != prevNxtBtn)
        {
            if (currNxtBtn == kLeftButton)
            {
                menu.userChoice--;
                if (menu.userChoice < 0)
                {
                    menu.userChoice = menu.numChoices - 1;
                }
            }
            else if (currNxtBtn == kRightButton)
            {
                menu.userChoice++;
                if (menu.userChoice >= menu.numChoices)
                {
                    menu.userChoice = 0;
                }
            }
            else if (currNxtBtn == kEnterButton)
            {
                break;
            }
            prevNxtBtn = currNxtBtn;
        }
        nxtDisplayTextLine(menu.startLine + menu.numChoices + 1,
                           "Choice? %d", menu.userChoice);
        wait1Msec(100);
    }

    TExit();
    return menu.userChoice;
}   //MenuGetChoice

/**
 *  This function waits for the start signal from the FCS or the enter button
 *  is pressed.
 */
void
MenuWaitStart()
{
    TButtons prevNxtBtn;
    TButtons currNxtBtn;

    TFuncName("MenuWaitStart");
    TLevel(API);
    TEnter();

    prevNxtBtn = nNxtButtonPressed;
    while (true)
    {
        getJoystickSettings(joystick);
        currNxtBtn = nNxtButtonPressed;
        if (!joystick.StopPgm ||
            (currNxtBtn != prevNxtBtn) && (currNxtBtn != kEnterButton))
        {
            break;
        }
        prevNxtBtn = currNxtBtn;
    }

    TExit();
    return;
}   //MenuWaitStart

#endif  //ifndef _MENU_H