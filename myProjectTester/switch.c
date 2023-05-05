#include "stateMachine.h"
#include "lcdutils.h"
#include "lcddraw.h"



void advanceState2(){
  fillRectangle(centerCol-20,centerRow-20, 40, 22, COLOR_BLUE); 
  static char state = 1;
  switch(state){
  case 0:
    forloop(0, -1);
    state++;
    break;
  case 1:
    forloop(-1, -1);
    state++;
    break;
  case 2:
    forloop(0, -1);
    state++;
    break;
  case 3:
    forloop(1, -1);
    state=0;
    break;
  }
}
