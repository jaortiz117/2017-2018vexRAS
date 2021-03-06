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
#include "MetaKnightMovementLogic.c"
#include "MetaKnightAuton.c"

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

  // Remove this function call once you have "real" code.
  //AutonomousCodePlaceholderForTesting();

  auton1();
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
    //UserControlCodePlaceholderForTesting();

  	//base
  	motor[baseBottomLeftMK] = vexRT[Ch3] + vexRT[Ch4];
  	motor[baseTopLeftMK] = vexRT[Ch3] + vexRT[Ch4];
  	motor[baseBottomRightMK] = -vexRT[Ch3] + vexRT[Ch4];
  	motor[baseTopRightMK] = -vexRT[Ch3] + vexRT[Ch4];

  	//lift

    int rightSpeed = 127-(127/3);

    int limitSwitch = SensorValue[limit];
      if(vexRT[Btn6U] == 0 && vexRT[Btn6D] == 1){
        motor(torreBackLeftMK) = 127;
        motor(torreFrontLeftMK) = 127;
        motor(torreBackRightMK) = -127;
        motor(torreFrontRightMK) = -127;
      }
      else if(vexRT[Btn6D] == 0 && vexRT[Btn6U] == 1
      && (limitSwitch == 0)){
        motor(torreBackLeftMK) = -127;
        motor(torreFrontLeftMK) = -127;
        motor(torreBackRightMK) = 127;
        motor(torreFrontRightMK) = 127;
      }
      else{
        motor(torreBackLeftMK) = 0;
        motor(torreFrontLeftMK) = 0;
        motor(torreBackRightMK) = 0;
        motor(torreFrontRightMK) = 0;
      }

  	//arm
  	if(vexRT[Btn8L] == 1
  		//&& vexRT[Btn8R] == 0
  		){
  		motor(leverArmMK) = 127/2;
  	}
  	else if(vexRT[Btn8R] == 1
  		//&& vexRT[Btn8L] == 0
  		){
  		motor(leverArmMK) = -127/2;
  	}
  	else{
  		motor(leverArmMK) = 0;
  	}

    //claw
    if(vexRT[Btn5U] == 0 && vexRT[Btn5D] == 1){
  		motor(claw) = 127;
  	}
  	else if(vexRT[Btn5U] == 1 && vexRT[Btn5D] == 0){
  		motor(claw) = -127;
  	}
  	else{
  		motor(claw) = 0;
  	}

  	//piston pusher
  	if(vexRT(Btn7D) == 1){
  		SensorValue[pistonMK] = 1;
  		wait1Msec(500);
  		SensorValue[pistonMK] = 0;
  	}
  	else{
  		SensorValue[pistonMK] = 0;
  	}

    if(vexRT(Btn8D) == 1){
      tester();
    }

  }
}
