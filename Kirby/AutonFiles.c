//#include "MotorAndSensorConfig.c"
#include "../MovementLogic.c"
#include "../SensorLogic.h"
//#include "../EncoderLogic.c"
//#include "baseRUMrobot.c"// temporary

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
  hightControl(1500);
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

void autonRedSide(){
  //Red autonomous pre loads side
  coneLift('U', 2900);
  coneLift('D',0);
  coneLift('U', 700);
  moveMG('D', 1100);
  Foward(1450);
  moveMG('U', 3300); //a~adir  un peque~o giro para enderesarse
  Backwards(200);
  coneLift('U',2900);
  SensorValue(claw)=1;
  wait1Msec(500);
  SensorValue(claw)=0;
  coneLift('D',700);
  Foward(150);
  /*coneLift('D',0);
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
  Backwards(600);
  Giro('R',450);
  Foward(150);
  Giro('R',450);
  moveMG('D',200);
  Foward(300);
  Backwards(500);
  Giro('L',450);
  Foward(200);
  Giro('L',450);
  moveMG('D',0);
  Foward(500);
  moveMG('U',1630);0*/


  // autonomous starting stationary goal
  /*	coneLift('U',700);
  Foward(500);
  towerHigh('U', 1000);
  coneLift('D', 0);
  SensorValue(claw) = 1;
  coneLift('U', 700);
  towerHigh('D', 700);
  Backwards(490);
  Giro('L', 450);
  Foward(500);
  Giro('R', 450);
  moveMG('D',0);
  Foward(800);
  moveMG('U', 900);
  Foward(250);*/
}

void skillsAuton(){
  //TODO make const for speeds, low, med, high, full
  //add a 100 ms delay between every function

  //move towards goal
  move(inToTicks(24), 60);
  lift(DOWN);
  move(inToTicks(12), 50);//pick up goal
  lift(UP);
  move(inToTicks(-6), 50);

  //move arm into game loads 3 times
  for(int i=0; i<2; i++){
    //clawOpen
    leverMove(IN);
    wait1Msec(500);
    //clawClose
  }

  // turn around towards corner
  encoderRotate(180, 90);
  move(inToTicks(48), 70);
  lift(DOWN);
  move(inToTicks(-12), 40);//release moving goal

  //rotate towards center//needs work
  encoderRotate(-45, 60);
  //move towards two goals
  move(inToTicks(48), 90);
  lift(DOWN);
  move(inToTicks(60), 40);
  lift(UP);//pickup two goals
  move(inToTicks(48), 90);//move towards other corner
  move(inToTicks(12), 60);//walk over tube
  lift(DOWN);
  move(inToTicks(-12), 60);

  //move to position looking at north blue tile
  encoderRotate(45+90, 40);

  //pickup and score blue goal
  move(inToTicks(6*12), 80);
  lift(DOWN);
  move(inToTicks(12), 40);
  lift(UP);//pickup blue GOAL
  move(inToTicks(-6*12), 80);
  encoderRotate(180, 40);
  move(inToTicks(12), 40);
  lift(DOWN);//release goal
  move(inToTicks(-12), 40);

  //position for south blue
  encoderRotate(180, 40);
  //rotate towards center//needs work
  encoderRotate(-45, 60);
  //move towards two goals
  move(inToTicks(48), 90);
  lift(DOWN);
  move(inToTicks(60), 40);
  lift(UP);//pickup two goals
  move(inToTicks(48), 90);//move towards other corner
  move(inToTicks(12), 60);//walk over tube
  lift(DOWN);
  move(inToTicks(-12), 60);

  //park at south red tile
  encoderRotate(-45-90, 40);
  move(inToTicks(24*3), 90);
}
