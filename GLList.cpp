#include <iostream>
using namespace std;
#include "glut.h"
#include "stdlib.h"
#include <cmath>

#define WIDTH 600
#define HEIGHT 600

#define ColoredVertex(c,v) do{glColor3fv(c);glVertex3fv(v);}while(0)

static GLfloat angle = 0.0f;

void myDisplay(void)
{
	static int list = 0;
	if (list == 0)
	{
		//GLfloat
		//	PointA[] = { 0.5f,-sqrt(6.0f) / 12,-sqrt(3.0f) / 6 },
		//	PointB[] = { -0.5f,-sqrt(6.0f) / 12,-sqrt(3.0f) / 6 },
		//	PointC[] = { 0.0f,-sqrt(6.0f) / 12,sqrt(3.0f) / 3 },
		//	PointD[] = { 0.0f,sqrt(6.0f) / 4,0 };

		//GLfloat
		//	ColorR[] = { 1,0,0 },
		//	ColorG[] = { 0,1,0 },
		//	ColorB[] = { 0,0,1 },
		//	ColorY[] = { 1,1,0 };

		GLfloat 
			Point1[] = { -0.5f,-0.5f,0.5f },
			Point2[] = { 0.5f,-0.5f,0.5f },
			Point3[] = { 0.5f,-0.5f,-0.5f },
			Point4[] = { -0.5f,-0.5f,-0.5f },
			Point5[] = { -0.5f,0.5f,0.5f },
			Point6[] = { 0.5f,0.5f,0.5f },
			Point7[] = { 0.5f,0.5f,-0.5f },
			Point8[] = { -0.5f,0.5f,-0.5f };

		GLfloat 
			Color17[] = { 1,0,0 },
			Color28[] = { 0,1,0 },
			Color35[] = { 0,0,1 },
			Color46[] = { 1,1,0 };

		list = glGenLists(1);
		glNewList(list, GL_COMPILE);
		glBegin(GL_QUADS);

		//ColoredVertex(ColorR, PointA);
		//ColoredVertex(ColorG, PointB);
		//ColoredVertex(ColorB, PointC);

		//ColoredVertex(ColorR, PointA);
		//ColoredVertex(ColorB, PointC);
		//ColoredVertex(ColorY, PointD);

		//ColoredVertex(ColorB, PointC);
		//ColoredVertex(ColorG, PointB);
		//ColoredVertex(ColorY, PointD);

		//ColoredVertex(ColorG, PointB);
		//ColoredVertex(ColorR, PointA);
		//ColoredVertex(ColorY, PointD);

		//1234
		ColoredVertex(Color17, Point1);
		ColoredVertex(Color28, Point2);
		ColoredVertex(Color35, Point3);
		ColoredVertex(Color46, Point4);

		//1256
		ColoredVertex(Color17, Point1);
		ColoredVertex(Color28, Point2);
		ColoredVertex(Color46, Point6);
		ColoredVertex(Color35, Point5);

		//2367
		ColoredVertex(Color28, Point2);
		ColoredVertex(Color35, Point3);
		ColoredVertex(Color17, Point7);
		ColoredVertex(Color46, Point6);

		//3478
		ColoredVertex(Color35, Point3);
		ColoredVertex(Color46, Point4);
		ColoredVertex(Color28, Point8);
		ColoredVertex(Color17, Point7);

		//1458
		ColoredVertex(Color17, Point1);
		ColoredVertex(Color46, Point4);
		ColoredVertex(Color28, Point8);
		ColoredVertex(Color35, Point5);

		//5678
		ColoredVertex(Color35, Point5);
		ColoredVertex(Color46, Point6);
		ColoredVertex(Color17, Point7);
		ColoredVertex(Color28, Point8);

		glEnd();
		glEndList();

		glEnable(GL_DEPTH_TEST);

	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angle, 1, 1, 0);
	glCallList(list);
	glPopMatrix();
	glutSwapBuffers();
}


void myIdle(void)
{
	angle += 0.1f;
	if (angle >= 360.0f)
	{
		angle = 0.0f;
	}
	myDisplay();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("My first OpenGL program");
	glutDisplayFunc(&myDisplay);
	glutIdleFunc(&myIdle);
	glutMainLoop();

	return 0;
}