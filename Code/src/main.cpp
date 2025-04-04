#include <Arduino.h>
#include <config.h>
#include <kinematics.h>

// put function declarations here:
double X,Y,Z;

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
  InverseKinematics(200,0);
  /*
  currentYPos = 0;
  HomeQ2();
  moveQ2(-90);
  HomeQ1();
  moveQ1(90);
  HomeQ3();
  HomeY();
  //Serial.println("Home Q1");
  delay(500);
  for(float z = 0; z < 300; z += 0.1){
    Y = z;
    X = -(pow((Y-150),2)/90)+300;
    Z = 0;
    moveAll(X,Y,Z);
    //delay(10);

  }
*/
}

void loop() {
  // put your main code here, to run repeatedly:
 
}

// put function definitions here:
