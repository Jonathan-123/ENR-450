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

  HomeY();
  Serial.begin(115200); 
  delay(10);
//////////
  moveY(60);
  delay(500);
  stepQ1(16000);
  delay(500);
  stepQ1(-16000);

  
}

void loop() {
  // put your main code here, to run repeatedly:
 
}

// put function definitions here:
