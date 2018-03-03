#include "MetaKnightMovementLogic.c"

void auton1()
{
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
