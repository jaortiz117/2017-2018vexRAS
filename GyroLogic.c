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
void resetGyro(tSensors gyro)
{
	//???
	SensorType[gyro] = sensorNone;
	wait1Msec(1000);
	SensorType[gyro] = sensorGyro;
	wait1Msec(500);
}

//getters

//gets absolute value of sensor (raw)
int getAbsGyro(tSensors gyro){
	return abs(SensorValue[gyro]);
}

/**********
Methods
**********/

//converts from raw sensor value to degrees of rotation
int gyroToDegree(tSensors sensor){
	int gyroVal = SensorValue[sensor];
	return gyroVal/GYRO_DIVISOR;
}
