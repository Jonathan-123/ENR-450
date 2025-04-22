#ifndef INPUT_H
#define INPUT_H

extern int pinY;
extern int dirY;
extern int homeLimitYMin;

extern int pinQ1;
extern int dirQ1;
extern int homeLimitQ1Min;

extern int pinQ2;
extern int dirQ2;
extern int homeLimitQ2Max;

extern int pinQ3;
extern int dirQ3;
extern int homeLimitQ3Max;

 //Stepper Motor Specs
extern int Y_uSTEP;
extern int Y_STEPS_PER_MM;
extern int YLENGTH; //STEPS (615 mm)

extern int YstepsPerRev;
extern int YPositive;
extern int YNegative;
extern int YDELAY;
//-----Q1-----
extern int Q1_uSTEP;
extern float Q1_STEPS_PER_DEGREE;
extern int Q1Negative;
extern int Q1Positive;
extern int Q1DELAY;
//-----Q2-----
extern int Q2_uSTEP;
extern float Q2_STEPS_PER_DEGREE;
extern int Q2Negative;
extern int Q2Positive;
extern int Q2DELAY;
//-----Q3-----
extern int Q3_uSTEP;
extern float Q3_STEPS_PER_DEGREE;
extern int Q3Negative;
extern int Q3Positive;
extern int Q3DELAY;



//Location Data
extern long currentYPos;
extern long desiredYPos;
extern int LimitY;
extern double currentQ1Pos;
extern double desiredQ1Pos;
extern int LimitQ1;
extern double currentQ2Pos;
extern double desiredQ2Pos;
extern int LimitQ2;
extern double currentQ3Pos;
extern double desiredQ3Pos;
extern int LimitQ3;

extern double theta1;
extern double theta2;
extern double theta3;
extern double theta4;

extern float L1;
extern float L2;
extern float L3;

extern double X_OFFSET;
extern double Y_OFFSET;

extern double RADS;

#endif