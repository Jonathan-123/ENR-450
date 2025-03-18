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
  Serial.begin(115200);
  Serial.println("hello");
 // HomeY();
 // Serial.println("Home Y");
  //delay(10);
  //moveY(100);
  //delay(500);
  HomeQ1();
  Serial.println("Home Q1");
  delay(500);
  //stepQ1(-8000);
  moveQ1(90);
 // delay(150);
 // moveQ1(111.4);
 // delay(150);
 // moveQ1(5.8);
 // delay(150);
 // moveQ1(152.6);
  //////////
  
  
  //stepQ1(8000);
 

  
}

void loop() {
  // put your main code here, to run repeatedly:
 
}

// put function definitions here:
