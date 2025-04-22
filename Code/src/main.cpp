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
  pinMode(homeLimitQ3Max, INPUT_PULLUP);
  
  Serial.begin(115200);
  Serial.println("hello");
  InverseKinematics(200,0);
  HomeY();
  //Parabolic Curve
  HomeY();
  currentQ3Pos = 0*Q3_STEPS_PER_DEGREE;
  moveQ3(-90);
  HomeQ2();
  delay(1000);
  moveQ2(-90);
  delay(500);
  HomeQ1();
  delay(500);
  moveQ1(90);
  //draw smile
  moveAll(50,200,15);
  delay(1000);
  moveAll(50,200,5);
  delay(1000);
  moveAll(50,200,0);
  delay(500);
  for(float z = 200; z < 400; z += 0.1){
    Y = z;
    X = -(pow((Y-300),2)/400)+75;
    Z = 0;
    moveAll(X,Y,Z);
    //delay(10);
  }
  delay(500);
  moveAll(50,400,50);

  //draw left eye
  moveAll(50,330,15);
  delay(1000);
  moveAll(50,330,5);
  delay(1000);
  moveAll(50,330,0);
  delay(100);
  moveAll(50,330,50);
  delay(500);

  //draw right eye
  moveAll(50,270,15);
  delay(1000);
  moveAll(50,270,5);
  delay(1000);
  moveAll(50,270,0);
  delay(100);
  moveAll(50,270,50);
  delay(500);
//end code

moveAll(0,0,50);
///////////


}

void loop() {
  // put your main code here, to run repeatedly:
 
}

// put function definitions here:
