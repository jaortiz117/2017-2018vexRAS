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
//#include "AutonFiles.c"
#include "../MovementLogic.c"
#include "../SensorLogic.h"

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////	 GLOBAL VARIABLES  	///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////	 FUNCTIONS  	/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

	//int liftHight[14];

bool stackConeListener;
bool stackConeIsRunning;

void setStackConeListener(bool listener){
		stackConeIsRunning = !listener;
		stackConeListener = listener;
}

bool getStackConeListener(){
	return stackConeListener;
}

bool getStackConeIsRunning(){
	return stackConeIsRunning;
}

task stackCone(){

		if(vexRT[Btn8U]==1){
				coneLift('U',700);
    		hightControl(2100);
    		coneLift('U',2900);
    		stack(2100);
    		SensorValue(claw) = 1;
    		wait1Msec(500);
    		hightControl(2100);
    		SensorValue(claw) = 0;
				wait1Msec(500);
				coneLift('D',1000);  // dont works perfectly
			}

			return;
}

task base(){

			motor[baseTopLeft]= vexRT[Ch3] + vexRT[Ch1];
    	motor[baseTopRight]= -vexRT[Ch3] + vexRT[Ch1];
    	motor[baseBottomLeft]= vexRT[Ch3] + vexRT[Ch1];
    	motor[baseBottomRight]= -vexRT[Ch3] + vexRT[Ch1];

    	return;

}


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

  SensorType[gyro]= sensorNone;

	SensorType[gyro]= sensorGyro;

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

	//auton1();
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
task controller(){
	while(true){
	//base
    	motor[baseTopLeft]= vexRT[Ch3] + vexRT[Ch1];
    	motor[baseTopRight]= -vexRT[Ch3] + vexRT[Ch1];
    	motor[baseBottomLeft]= vexRT[Ch3] + vexRT[Ch1];
    	motor[baseBottomRight]= -vexRT[Ch3] + vexRT[Ch1];


    //arcadeControl(Ch3, Ch1);// didnt have to do anything found pre existing functions

    	//transmition pneumatic
		   	if (vexRT[Btn7U] == 1){
		   		SensorValue[MGPiston] = 0;
		   	}

		   	else if (vexRT[Btn7D] == 1) {
		   		SensorValue[MGPiston] = 1;
		   	}


    //base extra motor
    if(SensorValue[MGPiston] == 1){
   		 motor[baseMG]= -vexRT[Ch3];
  	}

    //moving goal mech
 		if(SensorValue[MGPiston] == 0){
   		 if(vexRT[Btn7R] == 1){
   		 motor[baseMG]= -127;
   		}


   		else if(vexRT[Btn7L] == 1){
   		 motor[baseMG]= 127;
   		}

   		else{
   			motor[baseMG]= 0;
   		}
  	}

    //torre
    if((vexRT[Btn6U] == 1) && (vexRT[Btn6D] == 0)){
   	  motor(torreTopRight)= -127;
   	  motor(torreTopLeft) = 127;
    	motor(torreBottomLeft)= -127;
    	motor(torreBottomRight)= 127;
    }

    else if((vexRT[Btn6D] == 1) && (vexRT[Btn6U] == 0)){
    	motor(torreTopRight)= 127;
    	 motor(torreTopLeft) = -127;
    	motor(torreBottomLeft)= 127;
    	motor(torreBottomRight)= -127;
    }

    else {
    	motor(torreTopRight)= 0;
    	 motor(torreTopLeft) = 0;
    	motor(torreBottomLeft)= 0;
    	motor(torreBottomRight)= 0;
    }


    //chainBar pivot
    if((vexRT[Btn5U] == 1) && (vexRT[Btn5D] == 0)){
   	  motor(chainPivot) = -127;
    }

    else if((vexRT[Btn5D] == 1) && (vexRT[Btn5U] == 0)){
    	motor(chainPivot) = 127;
    }

    else {
    	motor(chainPivot) = 0;
    }


    //cone intake
    if(vexRT[Btn8D] == 1){
    	SensorValue[claw] = 1;
    }
    else {
    	SensorValue[claw] = 0;
    }

    //stack cones
    	if(vexRT[Btn8U] == 1){

				//startTask(stackCone);
    		startTask(base);


    		coneLift('U',700);
    		hightControl(2100);
    		coneLift('U',2900);
    		stack(2100);
    		SensorValue(claw) = 1;
    		wait1Msec(250);
    		hightControl(2100);
    		SensorValue(claw) = 0;
				wait1Msec(250);
				coneLift('D',2350);

				/********************/


				EndTimeSlice();



    	}
    	AbortTimeSlice();
    }
}
task usercontrol()
{
  // User control code here, inside the loop

	//bool active = false;

	StartTask(controller);
  while (true)
  {

  	if(vexRT[Btn8L] == 1 && vexRT[Btn8R] == 1){
  		StopTask(controller);
  		stopAllMotors();
  		wait1Msec(500);
  		StartTask(controller);
  		//break;
  	}

  	wait1Msec(10);
  }

	//startTask(usercontrol);
}
