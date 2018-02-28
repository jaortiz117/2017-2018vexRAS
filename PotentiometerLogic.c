//#include "MotorAndSensorConfig.c"

/*******************************************************************

	Handles Potentiometer Sensor logic and functions

*******************************************************************/

/**********
Constants

These numbers are based on testing
**********/
#define POT_MIN 5
#define POT_MAX 4092 //need to verify
#define SENSOR_AMOUNT 3

//sensor maximum and minimum values based their current locations
#define LIFT_LOW 670
#define LIFT_HIGH 2100
#define CONE_LOW 0
#define CONE_HIGH 2975

//globals
int sensors[SENSOR_AMOUNT][2] = {//array that stores each sensors' "settings"
	{POT_MIN, POT_MAX},
	{POT_MIN, POT_MAX},
	{POT_MIN, POT_MAX}};

//Re-maps a number from one range to another
int map(int x, int in_min, int in_max, int out_min, int out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//takes the name of the sensor and translates into index of array
int sensorToIndex(tSensors sensor){
	switch(sensor){

		case lift:
			return 0;
			break;

		case movingGoal:
			return 1;
			break;

		case chainBar:
			return 2;
			break;

		default:
			return -1;
	}
}

//setters

//sets a sensors max and min values
void setRange(tSensors sensor, int lowLimit, int highLimit){//limits in "ticks"

	int idx = sensorToIndex(sensor);

	sensors[idx][0] = lowLimit;
	sensors[idx][1] = highLimit;
}

//sets a sensors min value
void setOrigin(tSensors sensor, int val){//in "ticks"
	int idx = sensorToIndex(sensor);

	sensors[idx][0] = val;
}

//sets max value for a sensor
void setMax(tSensors sensor, int val){//in "ticks"
	int idx = sensorToIndex(sensor);

	sensors[idx][1] = val;
}

//getters

//get raw value from sensor
int getPot(tSensors sensor){
	return SensorValue(sensor);
}

//get value of sensor in degrees
int getPotDeg(tSensors sensor){
	int val = SensorValue(sensor);
	int idx = sensorToIndex(sensor);

	return map(val, sensors[idx][0], sensors[idx][1], 0, 250);
}

/**********
Methods
**********/

//initialize sensors
void initPots(){
	setRange(lift, LIFT_LOW, LIFT_HIGH);
	setRange(chainBar, CONE_LOW, CONE_HIGH);
	//setRange(movingGoal, GOAL_LOW, GOAL_HIGH);//TODO
}
