#include "MetaKnightMovementLogic.c"

void auton1()
{

  move(inToTicks(24), 60);
  lift(DOWN);
  move(inToTicks(12), 50);
  lift(UP);
  move(inToTicks(-6), 50);

  for(int i=0; i<3; i++){
    //clawOpen
    leverMove(IN);
    wait1Msec(500);
    //clawClose
  }

  encoderRotate(180, 90);
  move(inToTicks(48), 70);

}
