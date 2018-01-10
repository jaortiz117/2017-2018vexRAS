#include "MotorAndSensorConfig.c"
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
#include "MovementLogic.c"

/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////	 FUNCTIONS  	/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////
//////////////  FOWARD  /////////////////
/////////////////////////////////////////

void Foward(int forward)
{
	resetEncoders();

	while((absolutoizquierdoatras<forward)&&(absolutoderechoatras<forward))
	{
			absolutoizquierdoatras = abs(nMotorEncoder[baseTopLeft]);
			absolutoderechoatras  = abs(nMotorEncoder[baseTopRight]);

		if(absolutoizquierdofrente > absolutoderechofrente)
		{
			motor[LeftFront] =-58;
			motor[RightFront]=-60;
			motor[LeftBack]  =-58;
			motor[RightBack] =-60;
		}
  	else if(absolutoderechofrente < absolutoizquierdofrente)
		{
			motor[LeftFront] =-60;
			motor[RightFront]=-58;
			motor[LeftBack]  =-60;
			motor[RightBack] =-58;
		}
		else if(absolutoizquierdofrente==absolutoderechofrente)
		{
			motor[LeftFront] =-60;
			motor[RightFront]=-60;
			motor[LeftBack]  =-60;
			motor[RightBack] =-60;
		}
	}
	motor[LeftFront] =0;
	motor[RightFront]=0;
	motor[LeftBack]  =0;
	motor[RightBack] =0;
}
/////////////////////////////////////////
///////////  END FOWARD   ///////////////
/////////////////////////////////////////





/////////////////////////////////////////
////////////  BACKWARD  /////////////////
/////////////////////////////////////////

void Backward(int backward)
{
	resetEncoders();

	while((absolutoizquierdofrente<backward||absolutoizquierdoatras<backward)&&(absolutoderechofrente<backward||absolutoderechoatras<backward))
	{
		absolutoizquierdofrente = abs(nMotorEncoder[LeftFront]);
		absolutoizquierdoatras  = abs(nMotorEncoder[LeftBack]);
		absolutoderechoatras    = abs(nMotorEncoder[RightBack]);
		absolutoderechofrente   = abs(nMotorEncoder[RightFront]);

		if(absolutoizquierdofrente < absolutoderechofrente) // Derecho > Izquierdo
		{
			motor[LeftBack]  =50;
			motor[LeftFront] =50;
			motor[RightFront]=40;
			motor[RightBack] =40;
		}
  	else if(absolutoderechofrente < absolutoizquierdofrente)// Izquierdo > Derecho
		{
			motor[LeftFront] =45;
			motor[RightFront]=50;
			motor[LeftBack]  =45;
			motor[RightBack] =50;
		}
		else if(absolutoizquierdofrente==absolutoderechofrente)
		{
			motor[LeftFront] =50;
			motor[RightFront]=45;
			motor[LeftBack]  =50;
			motor[RightBack] =45;
		}
	}


}
/////////////////////////////////////////
///////////  END BACKWARD   /////////////
/////////////////////////////////////////





/////////////////////////////////////////
//////////////  GRIGHT  /////////////////
/////////////////////////////////////////

void gRight(int gright)
{
	resetEncoders();

	while((absolutoizquierdofrente<gright||absolutoizquierdoatras<gright)&&(absolutoderechofrente<gright||absolutoderechoatras<gright))
	{
		absolutoizquierdofrente = abs(nMotorEncoder[LeftFront]);
		absolutoizquierdoatras  = abs(nMotorEncoder[LeftBack]);
		absolutoderechoatras    = abs(nMotorEncoder[RightBack]);
		absolutoderechofrente   = abs(nMotorEncoder[RightFront]);

		if(absolutoizquierdofrente > absolutoderechofrente)
		{
			motor[LeftFront] =-58;
			motor[RightFront]= 60;
			motor[LeftBack]  =-58;
			motor[RightBack] = 60;
		}
  	else if(absolutoderechofrente < absolutoizquierdofrente)
		{
			motor[LeftFront] =-60;
			motor[RightFront]= 58;
			motor[LeftBack]  =-60;
			motor[RightBack] = 58;
		}
		else if(absolutoizquierdofrente==absolutoderechofrente)
		{
			motor[LeftFront] =-60;
			motor[RightFront]= 60;
			motor[LeftBack]  =-60;
			motor[RightBack] = 60;
		}
	}
	motor[LeftFront] =0;
	motor[RightFront]=0;
	motor[LeftBack]  =0;
	motor[RightBack] =0;
}
/////////////////////////////////////////
///////////  END GRIGHT   ///////////////
/////////////////////////////////////////





/////////////////////////////////////////
//////////////  GLEFT  //////////////////
/////////////////////////////////////////

void gLeft(int gleft)
{
	resetEncoders();

	while((absolutoizquierdofrente<gleft||absolutoizquierdoatras<gleft)&&(absolutoderechofrente<gleft||absolutoderechoatras<gleft))
	{
		absolutoizquierdofrente = abs(nMotorEncoder[LeftFront]);
		absolutoizquierdoatras  = abs(nMotorEncoder[LeftBack]);
		absolutoderechoatras    = abs(nMotorEncoder[RightBack]);
		absolutoderechofrente   = abs(nMotorEncoder[RightFront]);

		if(absolutoizquierdofrente > absolutoderechofrente)
		{
			motor[LeftFront] = 58;
			motor[RightFront]=-60;
			motor[LeftBack]  = 58;
			motor[RightBack] =-60;
		}
  	else if(absolutoderechofrente < absolutoizquierdofrente)
		{
			motor[LeftFront] = 60;
			motor[RightFront]=-58;
			motor[LeftBack]  = 60;
			motor[RightBack] =-58;
		}
		else if(absolutoizquierdofrente==absolutoderechofrente)
		{
			motor[LeftFront] = 60;
			motor[RightFront]=-60;
			motor[LeftBack]  = 60;
			motor[RightBack] =-60;
		}
	}
	motor[LeftFront] =0;
	motor[RightFront]=0;
	motor[LeftBack]  =0;
	motor[RightBack] =0;
}
/////////////////////////////////////////
///////////  END GLEFT   ////////////////
/////////////////////////////////////////

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

  	//base
    	motor[baseTopLeft]= vexRT[Ch3] + vexRT[Ch2];
    	motor[baseTopRight]= vexRT[Ch3] + vexRT[Ch2];
    	motor[baseBottomLeft]= vexRT[Ch3] + vexRT[Ch2];
    	motor[baseBottomRight]= vexRT[Ch3] + vexRT[Ch2];


    //arcadeControl(Ch3, Ch1);// didnt have to do anything found pre existing functions

    if(SensorValue(MGLeft) == 1 && SensorValue(MGRight) == 1){
   		 motor[baseMidLeft]= vexRT[Ch3] + vexRT[Ch2];
   		 motor[baseMidRight]= vexRT[Ch3] + vexRT[Ch2];
   	}


    //moving goal mech
   	if(SensorValue(MGLeft) == 0 && SensorValue(MGRight) == 0){

   		if(vexRT[Btn8R] == 1 && vexRT[Btn8L] == 0){
   		 motor[baseMidLeft]= -127;
   		 motor[baseMidRight]= -127;
   		}


   		if(vexRT[Btn8L] == 1 && vexRT[Btn8R] == 0){
   		 motor[baseMidLeft]= 127;
   		 motor[baseMidRight]= 127;
   		}

   		else {
   			 motor[baseMidLeft]= 0;
   			 motor[baseMidRight]= 0;
   		}

   	}

    //torre
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


    //chainBar pivot
    if(vexRT[Btn6U] == 1){
    	motor(chainPivotL)= 127;
    	motor(chainPivotR)= -127;
    }
    if(vexRT[Btn6D]) {
    	motor(chainPivotL)= -127;
    	motor(chainPivotR)= 127;
    }


    //cone intake
    if(vexRT[Btn8D] == 1){
    	SensorValue[claw] = 1;
    }
    else {
    	SensorValue[claw] = 0;
    }

  }
}
