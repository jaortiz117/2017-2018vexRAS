#include "MotorAndSensorConfig.c"
/****************************

Handles encoder sensor logic

****************************/


//must be moved to a different file
//void moveFront(int clicks)
//{

//	//move base motors a certain amount of clicks

//}
#define leftEncoder dgtl1
#define rightEncoder dgtl2


//init encoder values
//similar to how instance vars are used
int absolutoizquierdoatras;
int absolutoderechoatras;

//getters
int getAbsLeftBack(){
	return absolutoizquierdoatras;
}

int getAbsRightFront(){
	return absolutoderechoatras;
}


float getSpeed(int clicks){
	//calculate a motor's speed
	float speed;

	return speed;
}

void speedEqualize(float leftSpeed, float rightSpeed){
	//used to attenuate for motor speed inequalities
	//equalize motor speeds

}

//RESETING ENCODERS
void resetEncoders()
{
	//nMotorEncoder[baseTopLeft] = 0;
	//nMotorEncoder[baseTopRight]= 0;

	resetSensor(dgtl1);
	resetSensor(dgtl2);

	//other encoders must be added

	absolutoizquierdoatras = abs(nMotorEncoder[baseTopLeft]);
	absolutoderechoatras  = abs(nMotorEncoder[baseTopRight]);

}
