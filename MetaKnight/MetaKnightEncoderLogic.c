//#include "MotorAndSensorConfig.c"
/****************************

Handles encoder sensor logic

****************************/

/***********
Constants
***********/
#define PI 3.14

#define TICKS_REV 90
#define WHEEL_DIAMETER_IN 4


//globals

//setters

int getAbsEncoder(tSensors encoder){
	return abs(SensorValue[encoder]);
}

//get revolutions of wheel
float getRevs(int ticks){
	return ticks/TICKS_REV;
}

float getSpeed(int clicks){// rev/s
	//TODO
	//calculate a motor's speed
	float speed = clicks;//for now

	return speed;
}

/////////////
///METHODS///
/////////////

void encoderReset(tSensors encoder){

		resetSensor(encoder);

}

//CONVERTS FROM TICKS TO DISTANCE
float tickConvertIN(int ticks){
	//take x amount of ticks and convert into distance covered by wheel

	float circ = WHEEL_DIAMETER_IN*PI;
	float dist = circ*getRevs(ticks);
	return dist;
}

int inToTicks(float inches){
	//convert from inches and convert to ticks needed
	float circ = WHEEL_DIAMETER_IN*PI;
	float revs = inches/circ;
	int ticks = TICKS_REV*revs;

	return ticks;
}
