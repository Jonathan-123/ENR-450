#define Y_SPEED 30 //mm per second

//PINS
int pinY = 26;
int dirY = 25;
int homeLimitYMin = 18;

int pinQ1 = 14;
int dirQ1 = 27;
int homeLimitQ1Min = 19;

//Stepper Motor Specs
//-----Y-----
int Y_uSTEP = 16;
int Y_STEPS_PER_MM = 80;
int YLENGTH = 49250; //STEPS (615 mm)
int YstepsPerRev = 200;
int YPositive = 0;
int YNegative = 1;
int YDELAY = 6250/Y_SPEED;
//-----Q1-----
int Q1_uSTEP = 16;
float Q1_STEPS_PER_DEGREE = (200*Q1_uSTEP*10)/360;
int Q1Negative = 0;
int Q1Positive = 1;
int Q1DELAY = 150;

//Location Data
int currentYPos = 0;
int desiredYPos = 0;
int LimitY = 0;
float currentQ1Pos = 0;
float desiredQ1Pos = 0;
int LimitQ1 = 0;

float theta1 = 0 ;
float theta2 = 0 ;
float theta3 = 0 ;
float theta4 = 0 ;
