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
//similar to how instance vars are used
int absLeft;
int absRight;

//setters
//////////////////////////////
//		Legacy (will only work on kirby)
/////////////////////////////////
void setAbsLeft(int newVal){
	absLeft = newVal;
}

void setAbsRight(int newVal){
	absRight = newVal;
}

//getters
int getAbsLeft(){
	setAbsLeft(abs(SensorValue[baseLeft]));
	return absLeft;
}

int getAbsRight(){
	setAbsRight(abs(SensorValue[baseRight]));
	return absRight;
}
/////////////////////////////////
//		end Legacy
/////////////////////////////////

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
	float speed;

	return speed;
}

/////////////
///METHODS///
/////////////

//////////////////////////////
//		Legacy (will only work on kirby)
/////////////////////////////////
//RESETTING ENCODERS
void resetEncoders()
{
	resetSensor(baseLeft);
	resetSensor(baseRight);

	//other encoders must be added as they are added to the robot

	setAbsLeft(0);
	setAbsRight(0);
}
/////////////////////////////////
//		end Legacy
/////////////////////////////////

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
