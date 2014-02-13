#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S2,     ,               sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

			//####################################################################################//
			//																																										//
			//											 			  2013-2014 ProtoBoard Code	  		  										//
			//													  Team 3983 - Highlands Robotics													//
			//								    						Code by Xander Soldaat															//
			//																																										//
			//####################################################################################//

#include "Drivers\common.h"
#include "Drivers\hitechnic-protoboard.h"
#include "joystickdriver.c"

task main () {
  // Arrays to hold I2C message sent to slave and response
  sbyte I2Cmessage[4];
  sbyte I2Creply[1];

  // Configure port S1 to be a low speed I2C sensor.
  SetSensorType(S2, sensorLowSpeed);

  // Set the I2C slave address
  I2Cmessage[1] = 0x02;

  // Set the register we're interested in reading
  I2Cmessage[2] = 0x42;

  // Set the message size
  I2Cmessage[0] = 2;

  // Loop until the batteries run out.
  while (true) {
    // Send our message to the sensor and wait 20ms
    sendI2CMsg(S2, I2Cmessage[0], 1);
    wait1Msec(20);

    // Read the slave's response into the array
    // and print it to the screen and wait 100ms
    // before looping around again.
    readI2CReply(S2, I2Creply[0], 1);
    nxtDisplayBigTextLine(3, "%d", I2Creply[0]);
    wait1Msec(100);
  }
}
