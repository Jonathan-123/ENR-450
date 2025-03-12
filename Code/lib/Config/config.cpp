//#define Y_SPEED 30 //mm per second
//#define Y_uSTEP 16
//#define Y_STEPS_PER_MM 80
//#define YLENGTH 49250 //STEPS (615 mm)

//PINS
int pinY = 26;
int dirY = 25;
int homeLimitYMin = 18;

int pinQ1 = 14;
int dirQ1 = 27;
int homeLimitQ1Min = 0;

//Stepper Motor Specs
//-----Y-----
int Y_uSTEP = 16;
int Y_STEPS_PER_MM = 80;
int YLENGTH = 49250; //STEPS (615 mm)
int YstepsPerRev = 200;
int YPositive = 0;
int YNegative = 1;
int YDELAY = 100;
//-----Q1-----
int Q1_uSTEP = 16;
int Q1stepsPerRev = 200*Q1_uSTEP*8;
int Q1Negative = 0;
int Q1Positive = 1;
int Q1DELAY = 100;

//Location Data
int currentYPos = 0;
int desiredYPos = 0;
int LimitY = 0;
int currentQ1Pos = 0;
int desiredQ1Pos = 0;
int LimitQ1 = 0;

float theta1 = 0 ;
float theta2 = 0 ;
float theta3 = 0 ;
float theta4 = 0 ;
