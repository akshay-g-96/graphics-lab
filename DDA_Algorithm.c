#include<GL/glut.h>
#include<math.h>
//#include<device.h>
#define ROUND(a) ((int)(a+0.5))
void lineDDA(int xa, int ya, int xb, int yb)
{
int dx=xb-xa, dy=yb-ya, steps, k;
float xIncrement, yIncrement, x=xa, y=ya;
if(abs(dx)>abs(dy))
steps=abs(dx);
else
steps=abs(dy);
xIncrement = dx/(float)steps;
yIncrement = dy/(float)steps;
glBegin(GL_LINES);
glVertex2f(ROUND(x), ROUND(y));
glVertex2f(ROUND(y), ROUND(x));
glEnd();
glFlush();
}
void init2D(float r, float g, float b)
{
glClearColor(r, g, b, 0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}
void display()
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);
lineDDA(10, 20, 60, 70);
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitWindowSize(500, 500);
glutCreateWindow("simple");
init2D(0.0, 0.0, 0.0);
glutDisplayFunc(display);
glutMainLoop();
}
