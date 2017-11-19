	/*Program to draw mountain
	by Arun B Kovattu on 25/09/2015*/

	#include<iostream>
	#include<GL/glut.h>
	using namespace std;
	void House();
	void mountain(void)
	{
		glColor3f(.205,.135,.065);
		glBegin(GL_TRIANGLES);
			glVertex2f(20,150);	
			glVertex2f(100,450);	
			glVertex2f(180,150);
		glEnd();
		glBegin(GL_TRIANGLES);
			glVertex2f(160,150);
			glVertex2f(260,450);	
			glVertex2f(360,150);
		glEnd();
		
		glBegin(GL_TRIANGLES);
			glVertex2f(340,150);	
			glVertex2f(580,450);	
			glVertex2f(640,150);
		glEnd();
		glFlush();
		House();
	}		
	void House()
	{
		glColor3f(0.913,0.745,0.745);
		glBegin(GL_TRIANGLES);
			glVertex2f(20,50);	
			glVertex2f(50,100);	
			glVertex2f(80,50);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex2f(20,50);	
			glVertex2f(80,50);	
			glVertex2f(80,10);
			glVertex2f(20,10);
		glEnd();
		glFlush();
	}
	void reshape(int w, int h)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluOrtho2D(0,640,0,480);

	}
	void Init()
	{	
		glClearColor(1.0,1.0,1.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glColor3f(0,0,0);
		gluOrtho2D(0,640,0,480);
	}
	int main(int argc, char **argv)
	{
		glutInit(&argc,argv);
		glutCreateWindow("Mountain and house");
		Init();
		glutDisplayFunc(mountain);
		glPushMatrix();
		glTranslatef(415,233,0);
		glScalef(.5,.5,0);
		glRotatef(55,0,0,1);
		House();
		glPopMatrix();
		glPushMatrix();
		glutReshapeFunc(reshape);
		glTranslatef(400,0,0);
		glScalef(1.5,1.5,0);
		House();
		glPopMatrix();
		glutReshapeFunc(reshape);
		glutMainLoop();
		return 0;
	}
