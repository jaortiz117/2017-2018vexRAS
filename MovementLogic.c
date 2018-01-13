#include "MotorAndSensorConfig.c"
#include "EncoderLogic.c"

void moveticks(int ticks)//ticks: dist in ticks
{
	resetEncoders();

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
