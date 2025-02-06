// Compile with: gcc arena.c -o arena -lGL -lGLU -lglut
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#define Lx 600
#define Ly 600
#define PI 3.141592654

double RADS = PI/180;
double L1 = 300;
double L2 = 300;
double L3 = 300;
double theta1 = 140;
double theta2 = -50;
double theta3 = -70;

float 
	X0 = 0,
	X1 = 0,
	X2 = 250,
	X3 = 500,
	Y0 = 0,
	Y1 = 500,
	Y2 = 250,
	Y3 = 0;

void Initialize(void);
void display(void);
//void draw_box(void);
void draw_link1(void);
void draw_link2(void);
void draw_link3(void);
//void draw_points(void);
//void draw_polynomial(void);
void draw_axes(void);
void draw_bug(double, double);
void animate_bug(void);
void key(unsigned char, int, int);
void Timer (int);
void InverseKinematics(double, double);

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(1600, 1200);
    glutCreateWindow("Robot Arm Position");
    glutDisplayFunc(display);  // display function is display
	glutKeyboardFunc(key);     // keystroke interpreter is key
    Initialize();
	Timer(0);
    glutMainLoop();
    return 0;
}

void Initialize(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-Lx, Lx, -Ly/2, Ly);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
	draw_axes();
	draw_link1();
	draw_link2();
	draw_link3();
//	draw_bug(bug_x, bug_y);
	//draw_bug(i, j);
    glutSwapBuffers();
//	animate_bug();
}

void draw_axes(void){
    glColor3f(0.0, 0.5, 0.5);
    glBegin(GL_LINES);
        glVertex2f(-0.8*Lx, 0.0);
        glVertex2f(0.8*Lx, 0.0);
        glVertex2f(0.0, -0.4*Ly);
        glVertex2f(0.0, 0.8*Ly);
    glEnd();
}
void draw_link1(void){
	glColor3f(1.0,0.0,0.0);
	X1=L1*cos(theta1*RADS);
	Y1=L1*sin(theta1*RADS);
	glBegin(GL_LINE_LOOP);
		glVertex2f(X0,Y0);	
		glVertex2f(X1,Y1);	//link 1
	glEnd();             
}

void draw_link2(void){
	glColor3f(0.0,1.0,0.0);
	X2=L2*cos((theta1+theta2)*RADS) + X1;
	Y2=L2*sin((theta1+theta2)*RADS)+Y1;
	glBegin(GL_LINE_LOOP);
		glVertex2f(X1,Y1);	//link 1
		glVertex2f(X2,Y2);	//link 2
	glEnd();             
}

void draw_link3(void){
	glColor3f(0.0,0.0,1.0);
	X3=L3*cos((theta1+theta2+theta3)*RADS)+X2;
	Y3=L3*sin((theta1+theta2+theta3)*RADS)+Y2;
	glBegin(GL_LINE_LOOP);
		glVertex2f(X2,Y2);	//link 2
		glVertex2f(X3,Y3);	//link3, end effecter
	glEnd();             
}





void draw_bug(double x, double y){
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(20.0);
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
/* for circular bugs
		int sides = 10; 
		float R = 0.2;
		float PI = 3.14;
		glEnable(GL_LINE_SMOOTH);
		glLineWidth(5.0);
		glBegin(GL_LINES);
			glColor4f(0.4, 0.8, 0.9, 1.0);
			for(int i = 0; i <= sides; i++) {
				glVertex2f(x,y);
				glVertex2f( x+R*cos(2*PI*i/sides), y+R*sin(2*PI*i/sides) );
			}
		glEnd();
*/
}
/*
void animate_bug(void){
		// the following animates a black bug
		// the timer function calls the display function 
		// every 5 ms and that is what animates it via
		// the following
		bug_x += bug_vx;
		bug_y += bug_vy;
		if( bug_x >= X0 && bug_x <= X1) WAS_IN_X = 1;
		if( bug_y >= Y0 && bug_y <= Y3 + bug_x*(Y2-Y3)/(X2-X3)) WAS_IN_Y = 1;
		if( bug_x < X0 || bug_x > X1 && WAS_IN_X){ 
			bug_vx = -bug_vx;
			WAS_IN_X = 0;
		}
		if( bug_y < Y0 || bug_y > Y3 + bug_x*(Y2-Y3)/(X2-X3) && WAS_IN_Y){ 
			bug_vy = -bug_vy;
			WAS_IN_Y = 0;
		}
}
*/

void key(unsigned char key, int x, int y){
	switch(key) {
	case 'q': exit(0);
	default: break;
	}
}

void Timer (int iUnused){
	glutPostRedisplay();
	glutTimerFunc(5, Timer, 0);
}


