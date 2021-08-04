
#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void display();
void reshape(int,int);
//void timer(int); 

void init(){
	glClearColor(0.0,0.0,0.0,0.0);
}
int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("moving box");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutTimerFunc(0,timer,0); 
	init();
		glutMainLoop();
}
float x_position=-1.0;

//int state=1;

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//drawing
	glBegin(GL_POLYGON);
	glVertex2f(x_position,1.0);
	glVertex2f(x_position,-1.0);
	glVertex2f(x_position+2.0,-1.0);
	glVertex2f(x_position+2.0,1.0);
	glEnd();
	glutSwapBuffers();
}
void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}

/*void timer(int)
{
	
	glutPostRedisplay();

glutTimerFunc(1000/60,timer,0); 
switch(state)
{
case 1:
	if(x_position<8)
		x_position+=0.15;
	else
		state=-1;
	break;
case -1:
	if(x_position>-10)

		x_position-=0.15;
	else
		state=1;
	break;
}

	
}*/
