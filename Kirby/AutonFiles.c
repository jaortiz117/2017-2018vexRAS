#include "MotorAndSensorConfig.c"
#include "../MovementLogic.c"
#include "../SensorLogic.h"
#include "../EncoderLogic.c"

//constants

//types
// typedef struct Sides {//like a class
//    int dir;
// } Side;
//
// //globals
// Side left;
// left.dir = -1;
//
// Side right;
// right.dir = 1;

void auton()
{
	//autonomous code

  //here the code that takes the lcd inputs (whenever that is made)
  //for now just the individual functions probably controlled by jumpers
}

void auton1(){
  // Autonomous idea 1:		(view as starting from the red side)
  //
	// 	(pick moving goal, stack cones, score movin 20 pts zone, search other moving goal 10 pts zone)

  //(if we have time, search a cone and stack it in the stationary goal)
  // int dir = side.dir;

  moveFrontIN(24.0);
  Giro('L', 30);
  
}
