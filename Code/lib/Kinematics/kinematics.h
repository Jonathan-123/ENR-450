#ifndef KINEMATICS_H
#define KINEMATICS_H

void HomeY();
void HomeQ1();
void stepY(int steps);
void stepQ1(int steps);
void moveY(int yPos);
void InverseKinematics(int i, int j);

#endif