#include "MotorAndSensorConfig.c"

/*******************************************************************

	Handles Potentiometer Sensor logic and functions

*******************************************************************/

/**********
Constants
**********/
#define POT_MIN 5
#define POT_MAX 4092 //need to verify
#define SENSOR_AMOUNT 3

//globals
int sensors[SENSOR_AMOUNT][2] = {
	{POT_MIN, POT_MAX},
	{POT_MIN, POT_MAX},
	{POT_MIN, POT_MAX}};

//setters
void setRange(tSensors sensor, int lowLimit, int highLimit){//limits in "ticks" NOT degrees
	sensors[sensor][0] = lowLimit;
	sensors[sensor][1] = highLimit;
}

//getters
//int getPot(int sensor);
//int getPotDeg(int sensor);

/**********
Methods
**********/

//Re-maps a number from one range to another
int map(int x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
