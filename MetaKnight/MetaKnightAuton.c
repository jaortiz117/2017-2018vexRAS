#include "MetaKnightMovementLogic.c"

void auton1()
{

  //move towards goal
  move(inToTicks(24), 60);
  lift(DOWN);
  move(inToTicks(12), 50);//pick up goal
  lift(UP);
  move(inToTicks(-6), 50);

  //move arm into game loads 3 times
  for(int i=0; i<3; i++){
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
  move(inToTicks(6*12), 80);
  lift(DOWN);
  move(inToTicks(12), 40);
  lift(UP);


  //pickup and score blue goal

  //position for south blue initialize

  //pickup blue GOAL

  //move towards red corner

  //park at south red tile
}
