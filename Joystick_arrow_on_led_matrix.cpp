
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

const int  LRpin = A0; 
const int  UDpin = A1;

int LR;
int UD;

void setup() {
  matrix.begin();
}

uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void up_arrow(){
 
  frame[3][5] = 1; frame[2][5] = 1; frame[1][5] = 1;
  frame[0][5] = 1; frame[1][4] = 1; frame[1][6] = 1;
}
void clear_up_arrow(){
 
  frame[3][5] = 0; frame[2][5] = 0; frame[1][5] = 0;
  frame[0][5] = 0; frame[1][4] = 0; frame[1][6] = 0;
}


void upright_arrow(){
 
  frame[3][5] = 1; frame[2][6] = 1; frame[1][7] = 1;
  frame[0][8] = 1; frame[1][8] = 1; frame[0][7] = 1;
}
void clear_upright_arrow(){
 
  frame[3][5] = 0; frame[2][6] = 0; frame[1][7] = 0;
  frame[0][8] = 0; frame[1][8] = 0; frame[0][7] = 0;
}


void right_arrow(){
 
  frame[3][5] = 1; frame[3][6] = 1; frame[3][7] = 1;
  frame[3][8] = 1; frame[2][7] = 1; frame[4][7] = 1;
}
void clear_right_arrow(){
 
  frame[3][5] = 0; frame[3][6] = 0; frame[3][7] = 0;
  frame[3][8] = 0; frame[2][7] = 0; frame[4][7] = 0;
}
void downright_arrow(){
 
  frame[3][5] = 1; frame[4][6] = 1; frame[5][7] = 1;
  frame[6][8] = 1; frame[5][8] = 1; frame[6][7] = 1;
}
void clear_downright_arrow(){
 
  frame[3][5] = 0; frame[4][6] = 0; frame[5][7] = 0;
  frame[6][8] = 0; frame[5][8] = 0; frame[6][7] = 0;
}
void down_arrow(){
 
  frame[3][5] = 1; frame[4][5] = 1; frame[5][5] = 1;
  frame[6][5] = 1; frame[5][6] = 1; frame[5][4] = 1;
}
void clear_down_arrow(){
 
  frame[3][5] = 0; frame[4][5] = 0; frame[5][5] = 0;
  frame[6][5] = 0; frame[5][6] = 0; frame[5][4] = 0;
}
void downleft_arrow(){
 
  frame[3][5] = 1; frame[4][4] = 1; frame[5][3] = 1;
  frame[6][2] = 1; frame[6][3] = 1; frame[5][2] = 1;
}
void clear_downleft_arrow(){
  frame[3][5] = 0; frame[4][4] = 0; frame[5][3] = 0;
  frame[6][2] = 0; frame[6][3] = 0; frame[5][2] = 0;
}
void left_arrow(){
 
  frame[3][5] = 1; frame[3][4] = 1; frame[3][3] = 1;
  frame[3][2] = 1; frame[4][3] = 1; frame[2][3] = 1;
}
void clear_left_arrow(){
 
  frame[3][5] = 0; frame[3][4] = 0; frame[3][3] = 0;
  frame[3][2] = 0; frame[4][3] = 0; frame[2][3] = 0;
}
void leftup_arrow(){
 
  frame[3][5] = 1; frame[2][4] = 1; frame[1][3] = 1;
  frame[0][2] = 1; frame[0][3] = 1; frame[1][2] = 1;
}
void clear_leftup_arrow(){
 
  frame[3][5] = 0; frame[2][4] = 0; frame[1][3] = 0;
  frame[0][2] = 0; frame[0][3] = 0; frame[1][2] = 0;
}
void center(){
   frame[2][4] = 1; frame[2][5] = 1; frame[2][6] = 1;
   frame[3][4] = 1; frame[3][5] = 1; frame[3][6] = 1;
   frame[4][4] = 1; frame[4][5] = 1; frame[4][6] = 1;
}
void clear_center(){
   frame[2][4] = 0; frame[2][5] = 0; frame[2][6] = 0;
   frame[3][4] = 0; frame[3][5] = 0; frame[3][6] = 0;
   frame[4][4] = 0; frame[4][5] = 0; frame[4][6] = 0;
}
void loop(){
LR = analogRead(LRpin);
UD = analogRead(UDpin);


if(LR<341){
  if(UD<341){
    leftup_arrow();
      matrix.renderBitmap(frame, 8, 12);
     delay(100);
    clear_leftup_arrow();
     matrix.renderBitmap(frame, 8, 12);
  }
  if(UD>340 && UD<682){
    left_arrow();
      matrix.renderBitmap(frame, 8, 12);
    delay(100);
    clear_left_arrow();
     matrix.renderBitmap(frame, 8, 12);
  }
  if(UD>681){
    downleft_arrow();
      matrix.renderBitmap(frame, 8, 12);
     delay(100);
     clear_downleft_arrow();
      matrix.renderBitmap(frame, 8, 12);
  }
 
}
  if(LR>340 && LR<682){
  if(UD<341){
    up_arrow();
      matrix.renderBitmap(frame, 8, 12);
     delay(100);
    clear_up_arrow();
     matrix.renderBitmap(frame, 8, 12);
  }
  if(UD>340 && UD<682){
    center();
      matrix.renderBitmap(frame, 8, 12);
    delay(100);
    clear_center();
     matrix.renderBitmap(frame, 8, 12);
  }
  if(UD>681){
    down_arrow();
      matrix.renderBitmap(frame, 8, 12);
     delay(100);
     clear_down_arrow();
      matrix.renderBitmap(frame, 8, 12);
  }
 
}
if(LR>681){
  if(UD<341){
    upright_arrow();
      matrix.renderBitmap(frame, 8, 12);
     delay(100);
    clear_upright_arrow();
     matrix.renderBitmap(frame, 8, 12);
  }
  if(UD>340 && UD<682){
    right_arrow();
      matrix.renderBitmap(frame, 8, 12);
    delay(100);
    clear_right_arrow();
     matrix.renderBitmap(frame, 8, 12);
  }
  if(UD>681){
    downright_arrow();
      matrix.renderBitmap(frame, 8, 12);
     delay(100);
     clear_downright_arrow();
      matrix.renderBitmap(frame, 8, 12);
  }
 
}
}
