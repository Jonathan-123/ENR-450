#define Y_SPEED 30 //mm per second

//PINS
int pinY = 26;
int dirY = 25;
int homeLimitYMin = 18;

int pinQ1 = 33;
int dirQ1 = 32;
int homeLimitQ1Min = 4;

int pinQ2 = 13;
int dirQ2 = 27;
int homeLimitQ2Max = 16;

int pinQ3 = 14;
int dirQ3 = 12;
int homeLimitQ3Min = 19;
//Stepper Motor Specs
//-----Y-----
int Y_uSTEP = 16;
int Y_STEPS_PER_MM = 80;
int YLENGTH = 49250; //STEPS (615 mm)
int YstepsPerRev = 200;
int YNegative = 0;
int YPositive = 1;
int YDELAY = 6250/Y_SPEED;
//-----Q1-----
int Q1_uSTEP = 16;
float Q1_STEPS_PER_DEGREE = (200*Q1_uSTEP*10)/360;
int Q1Negative = 0;
int Q1Positive = 1;
int Q1DELAY = 300;
//-----Q2-----
int Q2_uSTEP = 16;
float Q2_STEPS_PER_DEGREE = (200*Q2_uSTEP*8)/360;
int Q2Negative = 0;
int Q2Positive = 1;
int Q2DELAY = 300;
//-----Q3-----
int Q3_uSTEP = 16;
float Q3_STEPS_PER_DEGREE = (200*Q3_uSTEP*10)/360;
int Q3Negative = 0;
int Q3Positive = 1;
int Q3DELAY = 300;

//Location Data
long currentYPos = 0;
long desiredYPos = 0;
int LimitY = 0;
double currentQ1Pos = 0;
double desiredQ1Pos = 0;
int LimitQ1 = 0;
double currentQ2Pos = 0;
double desiredQ2Pos = 0;
int LimitQ2 = 0;
double currentQ3Pos = 0;
double desiredQ3Pos = 0;
int LimitQ3 = 0;


double theta1 = 0 ;
double theta2 = 0 ;
double theta3 = 0 ;
double theta4 = 20 ;

float L1=353.16;
float L2=320.86;
float L3=120;

double X_OFFSET = 50;
double Y_OFFSET = 50;

double RADS = 0.0174532925;       // radains/degree
