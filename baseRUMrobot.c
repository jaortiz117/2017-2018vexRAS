#pragma config(Sensor, dgtl12, claw,           sensorDigitalOut)
#pragma config(Motor,  port1,           baseTopLeft,   tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port2,           baseTopRight,  tmotorVex393HighSpeed_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           baseMidLeft,   tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           torreTLBL,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           torreTRBR,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           goalMech,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           chainPivot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           baseMidRight,  tmotorVex393HighSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port9,           baseBottomLeft, tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port10,          baseBottomRight, tmotorVex393HighSpeed_HBridge, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "AutonFiles.c"
#include "EncoderLogic.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

	auton();


  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
    UserControlCodePlaceholderForTesting();

    /************
    motor[baseTopLeft]= vexRT[Ch3] + vexRT[Ch2];
    motor[baseTopRight]= vexRT[Ch3] + vexRT[Ch2];
    motor[baseMidLeft]= vexRT[Ch3] + vexRT[Ch2];
    motor[baseMidRight]= vexRT[Ch3] + vexRT[Ch2];
    motor[baseBottomLeft]= vexRT[Ch3] + vexRT[Ch2];
    motor[baseBottomRight]= vexRT[Ch3] + vexRT[Ch2];
    		*******************/
    // ^^^^^^ change this to an arcade six motor class like in easy C

    //base
    arcadeControl(Ch3, Ch1);// didnt have to do anything found pre existing functions

    //torre
    //motor[torreTLBR] = vexRT[Btn5U] + vexRT[Btn5D];//I dont think its gonna work
    //motor[torreTRBL] = vexRT[Btn5D] + vexRT[Btn5U];//probably mutliplying one by -1 or 127 will

    if((vexRT[Btn5U] == 1) && (vexRT[Btn5D] == 0)){
    	motor(torreTLBL)= 127;
    	motor(torreTRBR)= 127;
    }

    else if((vexRT[Btn5D] == 1) && (vexRT[Btn5U] == 0)){
    	motor(torreTLBL)= -127;
    	motor(torreTRBR)= -127;
    }

    else {
    	motor(torreTLBL)= 0;
    	motor(torreTRBR)= 0;
    }

    //moving goal mech
    motor[goalMech] = vexRT[Btn8U] + vexRT[Btn8D];

    //chainBar pivot
    motor[chainPivot] = vexRT[Btn7U] + vexRT[Btn7D];

    //claw
    if(vexRT[Btn6U] == 1){
    	SensorValue[claw] = 1;
    }
    else {
    	SensorValue[claw] = 0;
    }

  }
}
