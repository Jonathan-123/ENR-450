#ifndef INPUT_H
#define INPUT_H

extern int pinY;
extern int dirY;
extern int homeLimitYMin;

extern int pinQ1;
extern int dirQ1;
extern int homeLimitQ1Min;

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
extern int Q1stepsPerRev;
extern int Q1Negative;
extern int Q1Positive;
extern int Q1DELAY;



//Location Data
extern int currentYPos;
extern int desiredYPos;
extern int LimitY;
extern int currentQ1Pos;
extern int desiredQ1Pos;
extern int LimitQ1;



#endif