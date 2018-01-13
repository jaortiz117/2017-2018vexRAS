#include "MotorAndSensorConfig.c"
#include "EncoderLogic.c"

int direction = 1;
//TODO make 2 different braking functions
void suddenBrakes(){
	//for use when turning
	//stops instantly
}

void gradualBrakes(){
	//for use when moving forward or back
	//stops the robot gradually so it doesnt tip over
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
				setAbsLeft(abs(SensorValue[baseLeft]));
				setAbsRight(abs(SensorValue[baseRight]));


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

/**************************
	Move Back
***************************/
void moveBackward(int ticks)
{
	resetEncoders();
	direction = -1;

	while((getAbsLeft()<ticks)&&(getAbsRight()<ticks))
	{
				setAbsLeft(abs(SensorValue[baseBottomLeft]));
				setAbsRight(abs(SensorValue[baseBottomRight]));


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
