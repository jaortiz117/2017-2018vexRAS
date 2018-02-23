#include "MotorAndSensorConfig.c"
#include "EncoderLogic.c"

//consants
#define MOTOR_STOP 30

//globals
int direction = 1;
//TODO make 2 different braking functions

void baseMove(int leftSide, int rightSide){
	motor[baseTopLeft]= -leftSide;
	motor[baseTopRight]= -rightSide;
	motor[baseBottomLeft]= -leftSide;
	motor[baseBottomRight]= -rightSide;
}
void suddenBrakes(){
	//for use when turning
	//stops instantly

	baseMove(0,0);
}

int gradualBrakes(int currentSpeed, int distRemaining, int origDist){
  //for use when moving forward or back at speed
  //stops the robot gradually so it doesnt tip over

  //runs on every iteration of moveForward loop

  int speed = currentSpeed;

  if(origDist == 0){
    return 0;
  }

  if(distRemaining < origDist/4
      && currentSpeed > MOTOR_STOP){

    float reductCoeff = distRemaining/origDist;
    float decimalSpeed = reductCoeff * currentSpeed;
    speed = (int) ceil(decimalSpeed);
  }
  else if(currentSpeed < MOTOR_STOP){
    return 0;
  }

  //returns new speed
  return speed;
}


/*************************
	Move Forward
*************************/

void moveForward(int ticks)//ticks: dist in ticks
{
	resetEncoders();
	direction = 1;

	while((getAbsLeft()<ticks)&&(getAbsRight()<ticks))
	{
				//setAbsLeft(abs(SensorValue[baseLeft]));
				//setAbsRight(abs(SensorValue[baseRight]));


		if(getAbsLeft() > getAbsRight())
		{
			motor[baseTopLeft]= -58;
    	motor[baseTopRight]= -60;
    	motor[baseBottomLeft]= -58;
    	motor[baseBottomRight]= -60;

		}
  	else if(getAbsLeft() < getAbsRight())
		{

			motor[baseTopLeft]= -60;
    	motor[baseTopRight]= -58;
    	motor[baseBottomLeft]= -60;
    	motor[baseBottomRight]= -58;

		}
		else if(getAbsLeft()==getAbsRight())
		{
			motor[baseTopLeft]= -60;
    	motor[baseTopRight]= -60;
    	motor[baseBottomLeft]= -60;
    	motor[baseBottomRight]= -60;
		}
	}

	//use brake function instead of this stop
			motor[baseTopLeft]= 0;
    	motor[baseTopRight]= 0;
    	motor[baseBottomLeft]= 0;
    	motor[baseBottomRight]= 0;
}

//use inches as input to move
void moveFrontIN(float inches){
	moveForward(inToTicks(inches));
}

//TODO: move front with speed percentage

/**************************
	Move Back
***************************/
void moveBackward(int ticks)//I think this is redundant
{
	resetEncoders();
	direction = -1;

	while((getAbsLeft()<ticks)&&(getAbsRight()<ticks))
	{
				//setAbsLeft(abs(SensorValue[baseBottomLeft]));
				//setAbsRight(abs(SensorValue[baseBottomRight]));


		if(getAbsLeft() > getAbsRight())
		{
			motor[baseTopLeft]= 58;
    	motor[baseTopRight]= 60;
    	motor[baseBottomLeft]= 58;
    	motor[baseBottomRight]= 60;

		}
  	else if(getAbsLeft() < getAbsRight())
		{

			motor[baseTopLeft]= 60;
    	motor[baseTopRight]= 58;
    	motor[baseBottomLeft]= 60;
    	motor[baseBottomRight]= 58;

		}
		else if(getAbsLeft()==getAbsRight())
		{
			motor[baseTopLeft]= 60;
    	motor[baseTopRight]= 60;
    	motor[baseBottomLeft]= 60;
    	motor[baseBottomRight]= 60;
		}
	}
	//use brakes funct instead of this stop
	motor[baseTopLeft]= 0;
  motor[baseTopRight]= 0;
  motor[baseBottomLeft]= 0;
  motor[baseBottomRight]= 0;
}

//TODO place side equalizer appart from the move functions using encoder difference
//this way we can make equalizing more dynamic and that way more efficient
