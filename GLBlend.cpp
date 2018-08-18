#include <iostream>
using namespace std;
#include "glut.h"
#include "stdlib.h"
#include <cmath>

#define WIDTH 600
#define HEIGHT 600


//2D
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glEnable(GL_BLEND);
//	//glBlendFunc(GL_ONE, GL_ZERO);
//	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glBlendFunc(GL_ONE, GL_ONE);
//
//	glColor4f(1, 0, 0, 0.5);
//	glRectf(-1, -1, 0.5, 0.5);
//	glColor4f(0, 1, 0, 0.5);
//	glRectf(-0.5, -0.5, 1, 1);
//
//	glutSwapBuffers();
//}


//3D
void setLight(void)
{
	static const GLfloat light_position[] = { 1.0f,1.0f,-1.0f,1.0f };
	static const GLfloat light_ambient[] = { 0.2f,0.2f,0.2f,1.0f };
	static const GLfloat light_diffuse[] = { 1.0f,1.0f,1.0f,1.0f };
	static const GLfloat light_specular[] = { 1.0f,1.0f,1.0f,1.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void setMatirial(const GLfloat mat_diffuse[4], GLfloat mat_shininess)
{
	static const GLfloat mat_specular[] = { 0.0f,0.0f,0.0f,1.0f };
	static const GLfloat mat_emission[] = { 0.0f,0.0f,0.0f,1.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}

void myDisplay(void)
{
	const static GLfloat red_color[] = { 1.0f,0.0f,0.0f,1.0f };
	const static GLfloat green_color[] = { 0.0f,1.0f,0.0f,0.3f };
	const static GLfloat blue_color[] = { 0.0f,0.0f,1.0f,0.6f };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	setLight();
	setMatirial(red_color, 30.0);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.5f);
	glutSolidSphere(0.3, 30, 30);
	glPopMatrix();

	glDepthMask(GL_FALSE);

	setMatirial(blue_color, 30.0);
	glPushMatrix();
	glTranslatef(0.2f, 0.0f, -0.5f);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();

	setMatirial(green_color, 30.0);
	glPushMatrix();
	glTranslatef(0.1, 0, 0);
	glutSolidSphere(0.15, 30, 30);
	glPopMatrix();

	glDepthMask(GL_TRUE);

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("My first OpenGL program");
	glutDisplayFunc(&myDisplay);
	//glutIdleFunc(&myIdle);
	glutMainLoop();

	return 0;
}