
#include "Arduino_LED_Matrix.h" // adds the arduino led matrix libary
ArduinoLEDMatrix matrix; // sets the arduino led maxtrix to the name matrix

const int  LRpin = A0; // x-value pin 
const int  UDpin = A1; // y-value pin 

int LR; // the x-value variable 
int UD; // the y-value variable 

void setup() {
  matrix.begin(); 
}

uint8_t frame[8][12] = { // defines the confines of the led matrix and gives it 8 bit memory
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void up_arrow(){ // makes the up arrow on the led 
 
  frame[3][5] = 1; frame[2][5] = 1; frame[1][5] = 1;
  frame[0][5] = 1; frame[1][4] = 1; frame[1][6] = 1;
}
void clear_up_arrow(){ // turns off the up arrow on the led 
 
  frame[3][5] = 0; frame[2][5] = 0; frame[1][5] = 0;
  frame[0][5] = 0; frame[1][4] = 0; frame[1][6] = 0;
}


void upright_arrow(){ // makes the up right arrow on the led 
 
  frame[3][5] = 1; frame[2][6] = 1; frame[1][7] = 1;
  frame[0][8] = 1; frame[1][8] = 1; frame[0][7] = 1;
}
void clear_upright_arrow(){ // turns off the up right arrow on the led 
 
  frame[3][5] = 0; frame[2][6] = 0; frame[1][7] = 0;
  frame[0][8] = 0; frame[1][8] = 0; frame[0][7] = 0;
}


void right_arrow(){ // makes the right arrow on the led 
 
  frame[3][5] = 1; frame[3][6] = 1; frame[3][7] = 1;
  frame[3][8] = 1; frame[2][7] = 1; frame[4][7] = 1;
}
void clear_right_arrow(){ // turns off the right arrow on the led 
 
  frame[3][5] = 0; frame[3][6] = 0; frame[3][7] = 0;
  frame[3][8] = 0; frame[2][7] = 0; frame[4][7] = 0;
}
void downright_arrow(){ // makes the down right arrow on the led 
 
  frame[3][5] = 1; frame[4][6] = 1; frame[5][7] = 1;
  frame[6][8] = 1; frame[5][8] = 1; frame[6][7] = 1;
}
void clear_downright_arrow(){ // turns off the down right arrow on the led 
 
  frame[3][5] = 0; frame[4][6] = 0; frame[5][7] = 0;
  frame[6][8] = 0; frame[5][8] = 0; frame[6][7] = 0;
}
void down_arrow(){ // makes the down arrow on the led 
 
  frame[3][5] = 1; frame[4][5] = 1; frame[5][5] = 1;
  frame[6][5] = 1; frame[5][6] = 1; frame[5][4] = 1;
}
void clear_down_arrow(){ // turns off the down arrow on the led 
 
  frame[3][5] = 0; frame[4][5] = 0; frame[5][5] = 0;
  frame[6][5] = 0; frame[5][6] = 0; frame[5][4] = 0;
}
void downleft_arrow(){ // makes the down left arrow on the led 
 
  frame[3][5] = 1; frame[4][4] = 1; frame[5][3] = 1;
  frame[6][2] = 1; frame[6][3] = 1; frame[5][2] = 1;
}
void clear_downleft_arrow(){ // turns off the down left arrow on the led 
  frame[3][5] = 0; frame[4][4] = 0; frame[5][3] = 0;
  frame[6][2] = 0; frame[6][3] = 0; frame[5][2] = 0;
}
void left_arrow(){ // makes the left arrow on the led 
 
  frame[3][5] = 1; frame[3][4] = 1; frame[3][3] = 1;
  frame[3][2] = 1; frame[4][3] = 1; frame[2][3] = 1;
}
void clear_left_arrow(){ // turns off the left arrow on the led 
 
  frame[3][5] = 0; frame[3][4] = 0; frame[3][3] = 0;
  frame[3][2] = 0; frame[4][3] = 0; frame[2][3] = 0;
}
void leftup_arrow(){ // makes the left up arrow on the led 
 
  frame[3][5] = 1; frame[2][4] = 1; frame[1][3] = 1;
  frame[0][2] = 1; frame[0][3] = 1; frame[1][2] = 1;
}
void clear_leftup_arrow(){ // turns off the left up arrow on the led 
 
  frame[3][5] = 0; frame[2][4] = 0; frame[1][3] = 0;
  frame[0][2] = 0; frame[0][3] = 0; frame[1][2] = 0;
}
void center(){ // makes the center square on the led 
   frame[2][4] = 1; frame[2][5] = 1; frame[2][6] = 1;
   frame[3][4] = 1; frame[3][5] = 1; frame[3][6] = 1;
   frame[4][4] = 1; frame[4][5] = 1; frame[4][6] = 1;
}
void clear_center(){ // turns off the center on the led 
   frame[2][4] = 0; frame[2][5] = 0; frame[2][6] = 0;
   frame[3][4] = 0; frame[3][5] = 0; frame[3][6] = 0;
   frame[4][4] = 0; frame[4][5] = 0; frame[4][6] = 0;
}
void loop(){
LR = analogRead(LRpin); // makes the x-value variable equal the value from the x pin
UD = analogRead(UDpin); // makes the y-value variable equal the value from the y pin


if(LR<341){ // checks the left third of the joysticks possible x value 
  if(UD<341){ // checks the top third of the joysticks possible y value
    leftup_arrow();
      matrix.renderBitmap(frame, 8, 12); // updates the led matrix
     delay(100);
    clear_leftup_arrow();
     matrix.renderBitmap(frame, 8, 12);  
  }
  if(UD>340 && UD<682){ // checks the middle third of the joysticks possible y value
    left_arrow();
      matrix.renderBitmap(frame, 8, 12);
    delay(100);
    clear_left_arrow();
     matrix.renderBitmap(frame, 8, 12);
  }
  if(UD>681){ // checks the bottom third of the joysticks possible y value
    downleft_arrow();
      matrix.renderBitmap(frame, 8, 12);
     delay(100);
     clear_downleft_arrow();
      matrix.renderBitmap(frame, 8, 12);
  }
 
}
  if(LR>340 && LR<682){ //  checks the middle third of the joysticks possible x value 
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
if(LR>681){ //  checks the right third of the joysticks possible x value 
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
