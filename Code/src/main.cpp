#include <Arduino.h>
#include <config.h>
#include <kinematics.h>

// put function declarations here:


void setup() {
  //Y motor Pins
  pinMode(pinY, OUTPUT);
  pinMode(dirY, OUTPUT);
  pinMode(homeLimitYMin, INPUT_PULLUP);
//Q1 motor Pins
  pinMode(pinQ1, OUTPUT);
  pinMode(dirQ1, OUTPUT);
  pinMode(homeLimitQ1Min, INPUT_PULLUP);
  //Q1 motor Pins
  pinMode(pinQ2, OUTPUT);
  pinMode(dirQ2, OUTPUT);
  pinMode(homeLimitQ2Max, INPUT_PULLUP);
  //Q3 motor Pins
  pinMode(pinQ3, OUTPUT);
  pinMode(dirQ3, OUTPUT);
  //pinMode(homeLimitQ2Max, INPUT_PULLUP);
  
  Serial.begin(115200);
  Serial.println("hello");
  //HomeY();
  currentYPos = 0;
  HomeQ2();
  moveQ2(-90);
  HomeQ1();
  currentQ3Pos = 0;
  //Serial.println("Home Q1");
  delay(500);
  //moveAll(300, 0, 0);
  //moveAllBasic(300, 0, 0);
  delay(1000);
  moveAll(300,0,-150);
  delay(500);
  moveAll(300,600,-150);
  //InverseKinematics(400,300);
  //moveAll(400, 0, 300);
  //moveAllBasic(300, 0, 50);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
}

// put function definitions here:
