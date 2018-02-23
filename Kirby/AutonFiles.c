#include "MotorAndSensorConfig.c"
#include "../MovementLogic.c"
#include "../SensorLogic.h"
#include "../EncoderLogic.c"
#include "baseRUMrobot.c"// temporary

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

  moveFrontIN(36.0);
  Giro('L', 30);
  highControl(1500);
  moveMG('D', 0);
  moveFrontIN(12.0);
  Giro('R', 30);
  moveFrontIN(6.0);
  moveMG('U', 1000);

  //stack cone //TODO: make into function
  coneLift('U',700);
  hightControl(2100);
  coneLift('U',2900);
  stack(2100);
  SensorValue(claw) = 1;
  wait1Msec(250);
  hightControl(2100);
  SensorValue(claw) = 0;
  wait1Msec(250);
  coneLift('D',2350);
  /////////////////////////

  Giro('R', 180);
  moveFrontIN(54.0);
  Giro('R', 45);
  moveFrontIN(12.0);
  moveMG('D', 0);
  moveBackward(inToTicks(12.0));//needs a funct

}
