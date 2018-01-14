#include "MotorAndSensorConfig.c"

/*******************************************************************

	Handles Gyro Sensor logic and functions

*******************************************************************/

/**********
Constants
**********/

//globals
#define GYRO_DIVISOR 10 //10 "ticks" is a degree
//setters

//getters

/**********
Methods
**********/

//RESETS GYRO TO DEFAULT VALUE
void resetGyro()
{
	//???
	 SensorType[gyro] = sensorNone;
 		wait1Msec(1000);
 	 SensorType[gyro] = sensorGyro;
 		wait1Msec(1000);
}

int gyroToDegree(int gyroVal){
	return gyroVal/GYRO_DIVISOR;
}
