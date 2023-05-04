#include <msp430.h>
#include <stdio.h>
#include "libTimer.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachine.h"

char beatmax = 3;
char beat = 3;
void advanceState(){
  if (beat>=beatmax){ 
    buzzer_set_period(1000);
    beat=0;
  }
  else{
    buzzer_set_period(2000);
    beat++;
  }
}
void increaseBeatMax(){
  if(beatmax<6){
    beatmax++;
    drawTime();
  }
}
void decreaseBeatMax(){
  if(beatmax>3){
    beatmax--;
    drawTime();
  }
}
#define centerRow (screenHeight/2)
#define centerCol (screenWidth/2)
void advanceState2(){
  fillRectangle(centerCol-20,centerRow-20, 40, 22, COLOR_BLUE); 
  static char state = 1;
  switch(state){
  case 0:
    for (int i = 0; i<20; i++){
      drawPixel(centerCol, centerRow-i, COLOR_PINK);
        }
    state++;
    break;
  case 1:
    for(int i = 0; i<20; i++){
      drawPixel(centerCol-i, centerRow-i, COLOR_PINK);
    }
    state++;
    break;
  case 2:
    for(int i = 0; i<20; i++){
      drawPixel(centerCol, centerRow-i, COLOR_PINK);
    }
    state++;
    break;
  case 3:
    for(int i = 0; i<20; i++){
      drawPixel(centerCol+i, centerRow-i, COLOR_PINK);
    }
    state=0;
    break;
  }
}

void drawTempo(int tempo){
  char snum[3];
  sprintf(snum, "%d", tempo);
  fillRectangle(screenWidth-64, screenHeight-32, 64, 32, COLOR_BLUE);
  drawString11x16(screenWidth-64, screenHeight-32, snum, COLOR_RED, COLOR_BLUE);
}
void drawTime(){
  fillRectangle(20, screenHeight-32, 20, 32, COLOR_BLUE);
  drawChar11x16(20, screenHeight-33, beatmax+1+'0', COLOR_RED, COLOR_BLUE);
  drawChar11x16(20, screenHeight-16, '4', COLOR_RED, COLOR_BLUE);
}
