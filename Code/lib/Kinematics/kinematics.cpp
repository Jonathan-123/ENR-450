#include <Arduino.h>
#include <config.h>
#include <math.h>

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
  while(LimitQ1 != 1){
    digitalWrite(pinQ1, 1);
    delayMicroseconds(Q1DELAY);
    digitalWrite(pinQ1, 0);
    delayMicroseconds(Q1DELAY);
    LimitQ1 = digitalRead(homeLimitQ1Min);
    Serial.println(LimitQ1);
  }
  currentQ1Pos = 16350;
}
//Homes the Q2 Stepper Motor
void HomeQ2(){
  digitalWrite(dirQ2,Q2Positive);
  LimitQ2 = digitalRead(homeLimitQ2Max);
  while(LimitQ2 != 1){
    digitalWrite(pinQ2, 1);
    delayMicroseconds(Q2DELAY);
    digitalWrite(pinQ2, 0);
    delayMicroseconds(Q2DELAY);
    LimitQ2 = digitalRead(homeLimitQ2Max);
    Serial.println(LimitQ2);
  }
  currentQ2Pos = 168*Q2_STEPS_PER_DEGREE;
}
void HomeQ3(){
  currentQ3Pos = 0;
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
  //Serial.print("Sign = ");
  if(steps>0){
    digitalWrite(dirQ1,Q1Positive);
    SIGN = 1;  
  }
  if(steps<0){
    digitalWrite(dirQ1,Q1Negative);  
    SIGN = -1;
  }
  //Serial.println(SIGN);  
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

//moves Q2stepper a number of steps
void stepQ2(int steps){
  int SIGN = 0;
  //Serial.print("Sign = ");
  if(steps>0){
    digitalWrite(dirQ2,Q2Positive);
    SIGN = 1;  
  }
  if(steps<0){
    digitalWrite(dirQ2,Q2Negative);  
    SIGN = -1;
  }
  //Serial.println(SIGN);  
  steps = abs(steps);
  for(int i=0; i<steps; i++){
    digitalWrite(pinQ2, 1);
    delayMicroseconds(Q2DELAY);
    digitalWrite(pinQ2, 0);
    delayMicroseconds(Q2DELAY);
    currentQ2Pos = currentQ2Pos +(SIGN);
  }
  //Serial.println(currentYPos/80);
}

//moves Q3stepper a number of steps
void stepQ3(int steps){
  int SIGN = 0;
  //Serial.print("Sign = ");
  if(steps>0){
    digitalWrite(dirQ3,Q3Positive);
    SIGN = 1;  
  }
  if(steps<0){
    digitalWrite(dirQ3,Q3Negative);  
    SIGN = -1;
  }
  //Serial.println(SIGN);  
  steps = abs(steps);
  for(int i=0; i<steps; i++){
    digitalWrite(pinQ3, 1);
    delayMicroseconds(Q3DELAY);
    digitalWrite(pinQ3, 0);
    delayMicroseconds(Q3DELAY);
    currentQ3Pos = currentQ3Pos +(SIGN);
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

//moves Q1stepper to an absolute Theta1 position
void moveQ1 (float Q1Pos){
  float Q1Steps = Q1Pos / 0.01125;
  float deltaQ1Steps = Q1Steps - currentQ1Pos;
  //Serial.println(deltaQ1Steps);
  int deltaQ1StepsInt = static_cast<int>(deltaQ1Steps);
  stepQ1(deltaQ1StepsInt);
  //Serial.print(currentQ1Pos*0.01125);
  //Serial.println(" degrees - Theta1");
}

void moveQ2 (float Q2Pos){
  float Q2Steps = Q2Pos / 0.01406;
  float deltaQ2Steps = Q2Steps - currentQ2Pos;
  //Serial.println(deltaQ1Steps);
  int deltaQ2StepsInt = static_cast<int>(deltaQ2Steps);
  stepQ2(deltaQ2StepsInt);
  //Serial.print(currentQ2Pos*0.01406);
  //Serial.println(" degrees - Theta1");
}

void InverseKinematics(double i, double j){
  j = j + L3;
  float omega = (-90*RADS);
//  float omega = (90*RADS) + theta4;
  theta2 = -acos((pow(i,2) + pow(j,2)-pow(L1,2)-pow(L2,2))/(2*L1*L2));
  theta1 = atan2(j,i) - atan2((L1*sin(theta2)),(L1+(L2*cos(theta2))));
  theta3 = (omega) - theta1 - theta2;
  Serial.print(theta1/RADS);
  Serial.print("\t");
  Serial.print(theta2/RADS);
  Serial.print("\t");
  Serial.println(theta3/RADS);
}


void moveAll(float X, float Y, float Z){
  Q1DELAY = 100;
  Q2DELAY = 100;
  float Q1Pos, Q2Pos, Q3Pos;  
  InverseKinematics(X, Z);
//calculate absolute position delta, then convert into an int number of steps
  //Theta1
  float Q1Steps = Q1Pos / 0.01125;
  float deltaQ1Steps = Q1Steps - currentQ1Pos;
  int deltaQ1StepsInt = static_cast<int>(deltaQ1Steps);
  //Theta2
  float Q2Steps = Q2Pos / 0.01125;
  float deltaQ2Steps = Q2Steps - currentQ2Pos;
  int deltaQ2StepsInt = static_cast<int>(deltaQ2Steps);
  //Theta3
  float Q3Steps = Q3Pos / 0.01125;
  float deltaQ3Steps = Q3Steps - currentQ3Pos;
  int deltaQ3StepsInt = static_cast<int>(deltaQ3Steps);
  //Y 
  int deltaY = Y - (currentYPos/80);
  int deltaYSteps = deltaY * Y_STEPS_PER_MM;

  int SIGN1, SIGN2, SIGN3, SIGNY;
  if(deltaQ1StepsInt>=0){
    digitalWrite(dirQ1,Q1Positive);
    SIGN1 = 1;  
  }
  if(deltaQ1StepsInt<0){
    digitalWrite(dirQ1,Q1Negative);  
    SIGN1 = -1;
  }
  if(deltaQ2StepsInt>=0){
    digitalWrite(dirQ2,Q2Positive);
    SIGN2 = 1;  
  }
  if(deltaQ2StepsInt<0){
    digitalWrite(dirQ2,Q2Negative);  
    SIGN2 = -1;
  }
  if(deltaQ3StepsInt>=0){
    digitalWrite(dirQ3,Q3Positive);
    SIGN3 = 1;  
  }
  if(deltaQ3StepsInt<0){
    digitalWrite(dirQ3,Q3Negative);  
    SIGN3 = -1;
  }
  if(deltaYSteps>=0){
    digitalWrite(dirY,YPositive);
    SIGNY = 1;  
  }
  if(deltaY<0){
    digitalWrite(dirY,YNegative);  
    SIGNY = -1;
  }

  //Calculate the maximum number of steps for the theta motors
  //change all these to absolute values, PLACEHOLDER
  int maximumSteps =0;
  if (abs(deltaQ1StepsInt) >= abs(deltaQ2StepsInt)){
    if (abs(deltaQ1StepsInt) >= abs(deltaQ3StepsInt)) maximumSteps = abs(deltaQ1StepsInt);
    else maximumSteps = abs(deltaQ3StepsInt);
  }
  else{
    if (abs(deltaQ2StepsInt) >= abs(deltaQ3StepsInt)) maximumSteps = abs(deltaQ2StepsInt);
    else maximumSteps = abs(deltaQ3StepsInt);
  }
  //is maximumSteps greater than or less than Y steps?
  if (maximumSteps < abs(deltaYSteps)) maximumSteps = abs(deltaYSteps);
  else maximumSteps = maximumSteps;
  //For loop that runs for the maximum number of steps
  for (int BLAH=0; BLAH < maximumSteps; BLAH++){
    if(deltaY != 0){
      stepY(1*SIGNY);
      deltaY = deltaY + SIGNY;
    }
    if(deltaQ1StepsInt != 0){
      stepQ1(1*SIGN1);
      deltaQ1StepsInt = deltaQ1StepsInt + SIGN1;
    }
    if(deltaQ2StepsInt != 0){
      stepQ2(1*SIGN2);
      deltaQ2StepsInt = deltaQ2StepsInt + SIGN2;
    }
    if(deltaQ3StepsInt != 0){
      stepQ3(1*SIGN3);
      deltaQ3StepsInt = deltaQ3StepsInt + SIGN3;
    }
  }
  Q1DELAY = 300;
  Q2DELAY = 300;

  Serial.print(currentQ1Pos*0.01125);
  Serial.println(" degrees - Theta1");
  Serial.print(currentQ2Pos*0.01406);
  Serial.println(" degrees - Theta2");
}


  