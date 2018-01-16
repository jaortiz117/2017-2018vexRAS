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

//Re-maps a number from one range to another
int map(int x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//setters
void setRange(tSensors sensor, int lowLimit, int highLimit){//limits in "ticks"
	sensors[sensor][0] = lowLimit;
	sensors[sensor][1] = highLimit;
}

void setOrigin(tSensors sensor, int val){//in "ticks"
	sensors[sensor][0] = val;
}

void setMax(tSensors sensor, int val){//in "ticks"
	sensors[sensor][1] = val;
}

//getters
int getPot(tSensors sensor){
	return SensorValue(sensor);
}
int getPotDeg(tSensors sensor){
	int val = SensorValue(sensor);
	return map(val, sensors[sensor][0], sensors[sensor][1], 0, 250);
}

/**********
Methods
**********/
