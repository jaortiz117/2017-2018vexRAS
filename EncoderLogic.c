#include "MotorAndSensorConfig.c"
/****************************

Handles encoder sensor logic

****************************/


#define LEFT_ENCODER dgtl1
#define RIGHT_ENCODER dgtl2

#define PI 3.14

#define TICKS_REV 90
#define WHEEL_DIAMETER_IN 4


//init encoder values
//similar to how instance vars are used
int absLeft;
int absRight;

//getters
int getAbsLeftBack(){
	return absLeft;
}

int getAbsRightFront(){
	return absRight;
}


float getSpeed(int clicks){
	//calculate a motor's speed
	float speed;

	return speed;
}

float getRevs(int ticks){
	return ticks/TICKS_REV;
}

//setters

void setAbsLeft(int newVal){
	absLeft = newVal;
}

void setAbsRight(int newVal){
	absRight = newVal;
}

/////////////
///METHODS///
/////////////

//attenuates speed between both sides
void speedEqualize(float leftSpeed, float rightSpeed){
	//used to attenuate for motor speed inequalities
	//equalize motor speeds

}

//RESETTING ENCODERS
void resetEncoders()
{
	resetSensor(LEFT_ENCODER);
	resetSensor(RIGHT_ENCODER);

	//other encoders must be added

	setAbsLeft(0);
	setAbsRight(0);
}

//CONVERTS FROM TICKS TO DISTANCE
float tickConvertIN(int ticks){
	//take x amount of ticks and convert into distance covered by wheel

	float circ = WHEEL_DIAMETER_IN*PI;
	float dist = circ*getRevs(ticks);
	return dist
}
