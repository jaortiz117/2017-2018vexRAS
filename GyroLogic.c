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
//RESETS GYRO TO DEFAULT VALUE
void resetGyro()
{
	//???
	SensorType[gyro] = sensorNone;
	wait1Msec(1000);
	SensorType[gyro] = sensorGyro;
	wait1Msec(500);
}

//getters
int getAbsGyro(tSensors gyro){
	return abs(SensorValue[gyro]);
}

/**********
Methods
**********/

int gyroToDegree(tSensors sensor){
	int gyroVal = SensorValue[sensor];
	return gyroVal/GYRO_DIVISOR;
}
