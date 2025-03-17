#include <Arduino.h>
#include <config.h>


//Homes the Y stepper motor
void HomeY(){
  digitalWrite(dirY,YNegative);
  LimitY = digitalRead(homeLimitYMin);
  while(LimitY != 1){
    digitalWrite(pinY, 1);
    delayMicroseconds(YDELAY);
    digitalWrite(pinY, 0);
    delayMicroseconds(YDELAY);
    LimitY = digitalRead(homeLimitYMin);
  }
  currentYPos = 0;
}
//Homes the Q1 Stepper Motor
void HomeQ1(){
  digitalWrite(dirQ1,Q1Positive);
  LimitQ1 = digitalRead(homeLimitQ1Min);
  while(LimitQ1 != 0){
    digitalWrite(pinQ1, 1);
    delayMicroseconds(Q1DELAY);
    digitalWrite(pinQ1, 0);
    delayMicroseconds(Q1DELAY);
    LimitQ1 = digitalRead(homeLimitQ1Min);
  }
  currentQ1Pos = 0;
}

//moves Ystepper a number of steps
void stepY(int steps){
  int SIGN = 0;
  if(steps>0){
    digitalWrite(dirY,YPositive);
    SIGN = 1;  
  }
  if(steps<0){
    digitalWrite(dirY,YNegative);  
    SIGN = -1;
  }  
  steps = abs(steps);
  for(int i=0; i<steps; i++){
    digitalWrite(pinY, 1);
    delayMicroseconds(YDELAY);
    digitalWrite(pinY, 0);
    delayMicroseconds(YDELAY);
    currentYPos = currentYPos +(SIGN);  
  }
  //Serial.println(currentYPos/80);
}
//moves Q1stepper a number of steps
void stepQ1(int steps){
  int SIGN = 0;
  if(steps>0){
    digitalWrite(dirQ1,Q1Positive);
    SIGN = 1;  
  }
  if(steps<0){
    digitalWrite(dirQ1,Q1Negative);  
    SIGN = -1;
  }  
  steps = abs(steps);
  for(int i=0; i<steps; i++){
    digitalWrite(pinQ1, 1);
    delayMicroseconds(Q1DELAY);
    digitalWrite(pinQ1, 0);
    delayMicroseconds(Q1DELAY);
    currentQ1Pos = currentQ1Pos +(SIGN);  
  }
  //Serial.println(currentYPos/80);
}

//moves Ystepper to an absolute Y position
void moveY(int yPos){
  int deltaY = yPos - (currentYPos/80);
  int deltaYSteps = deltaY * Y_STEPS_PER_MM;
  //Serial.println(deltaY);
  stepY(deltaYSteps);
}

//moves Ystepper to an absolute Y position
void moveQ1 (float Q1Pos){
  //float deltaQ1 = Q1Pos - (currentQ1Pos/80);  //80 needs to be changed
  //float deltaQ1Steps = deltaQ1 * Q1_STEPS_PER_DEGREE;
  float deltaQ1Steps = Q1Pos*Q1_STEPS_PER_DEGREE - currentQ1Pos;
  //Serial.println(deltaQ1Steps);
  stepQ1((int)deltaQ1Steps);
}
/*
void InverseKinematics(int i, int j){
    float omega = 90 + theta4;
    theta2 = -acos(pow(i,2) + pow(j,2)-pow(L1,2)-pow(L2,2)/(2*L1*L2));
    theta1 = atan2(j,i) - atan2((L1*sin(theta2)),(L1+(L2*sin(theta2))));
    theta3 = (omega*RADS) - theta1 - theta2;
}
    */