#include <Arduino.h>
#include <config.h>
#include <kinematics.h>
#include <FastAccelKinematics.h>


// put function declarations here:
void moveQ2Fast (float Q2Pos);
void HomeQ2Fast();

FastAccelStepperEngine engine=FastAccelStepperEngine();
FastAccelStepper *steppery;
FastAccelStepper *stepper1;
FastAccelStepper *stepper2;
FastAccelStepper *stepper3; 


void setup() {
 
  engine.init(1);

  steppery=engine.stepperConnectToPin(pinY,0);
  steppery->setDirectionPin(dirY);
  steppery->setSpeedInUs(300);
  steppery->setAcceleration(100);

  stepper1=engine.stepperConnectToPin(pinQ1,0);
  stepper1->setDirectionPin(dirQ1);

  stepper2=engine.stepperConnectToPin(pinQ2,0);
  stepper2->setDirectionPin(dirQ2);
  stepper2->setAutoEnable(false);
  stepper2->setSpeedInUs(300);
  stepper2->setAcceleration(100);

  stepper3=engine.stepperConnectToPin(pinQ3,0);
  stepper3->setDirectionPin(dirQ3);

  
  //Y motor Pins
  //pinMode(pinY, OUTPUT);
  //pinMode(dirY, OUTPUT);
  pinMode(homeLimitYMin, INPUT_PULLUP);
//Q1 motor Pins
  //pinMode(pinQ1, OUTPUT);
  //pinMode(dirQ1, OUTPUT);
  pinMode(homeLimitQ1Min, INPUT_PULLUP);
  //Q1 motor Pins
  //pinMode(pinQ2, OUTPUT);
  //pinMode(dirQ2, OUTPUT);
  pinMode(homeLimitQ2Max, INPUT_PULLUP);
  //Q3 motor Pins
  //pinMode(pinQ3, OUTPUT);
  //pinMode(dirQ3, OUTPUT);
  //pinMode(homeLimitQ2Max, INPUT_PULLUP);
  
  Serial.begin(115200);
  Serial.println("hello");
  //HomeY();
  currentYPos = 0;
  HomeQ2Fast();
  //moveQ2Fast(-90);
  //HomeQ1();
  //HomeQ3();
  //delay(500);
  //delay(1000);
  //moveAll(300,0,-150);
  //delay(500);
  //moveAll(300,600,-150);  
}

void loop() {
  // put your main code here, to run repeatedly:
 
}

// put function definitions here:

//Homes the Q2 Stepper Motor
void HomeQ2Fast(){
  stepper2->setSpeedInUs(450);
  stepper2->setAcceleration(50);
  stepper2->move(12000);
  while(digitalRead(homeLimitQ2Max) == LOW){

  }
  stepper2->stopMove();
  delay(100);
  stepper2->setCurrentPosition(168*Q2_STEPS_PER_DEGREE);
  currentQ2Pos = 168*Q2_STEPS_PER_DEGREE;
  stepper2->setSpeedInUs(300);
  stepper2->setAcceleration(50);
}

void moveQ2Fast (float Q2Pos){
  float Q2Steps = Q2Pos / 0.01406;
  float deltaQ2Steps = Q2Steps - currentQ2Pos;
  //Serial.println(deltaQ1Steps);
  int deltaQ2StepsInt = static_cast<int>(deltaQ2Steps);
  stepper2->move(deltaQ2StepsInt);
  Serial.print(currentQ2Pos*0.01406);
  Serial.println(" degrees - Theta2");
}