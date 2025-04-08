#ifndef KINEMATICS_H
#define KINEMATICS_H

void HomeY();
void HomeQ1();
void HomeQ2();
void HomeQ3();
void stepY(int steps);
void stepQ1(int steps);
void stepQ2(int steps);
void stepQ3(int steps);
void moveY(int yPos);
void moveQ1 (float Q1Pos);
void moveQ2 (float Q2Pos);
void moveQ3 (float Q3Pos);
void InverseKinematics(double i, double j);
void moveAllBasic(float X, float Y, float Z);
void moveAll(float X, float Y, float Z);
#endif