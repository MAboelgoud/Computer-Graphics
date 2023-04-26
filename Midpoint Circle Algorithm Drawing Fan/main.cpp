#include <iostream>
#include <gl\glut.h>
#include <math.h>
#include <ctime>
using namespace std;



int x_center = 0;
int y_center = 0;
int radius = 400;


//Creates the main window
void InitGraphics(int argc, char *argv[]);


//Sets the logical coordinate system
void SetTransformations();


//rendering code
void OnDisplay();

//make point
void setPixel(GLint , GLint );

//make line
void linePlot (GLint x0,GLint y0,GLint x1,GLint y1)
{
    glLineStipple(1, 0x1C47);
    glBegin(GL_LINES);
        glVertex2i( x0, y0);
        glVertex2i(x1,y1);
    glEnd();
}


int main(int argc, char* argv[]) {

    InitGraphics(argc, argv);

	return 0;

}



void InitGraphics(int argc, char *argv[]) {
	glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 100);

	glutCreateWindow("OpenGL Assignment2 by Moahmed Hesham");
	SetTransformations();
	//OnDisplay will handle the paint event
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
}


void SetTransformations() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);

}


//make point
void setPixel(GLint xcoordinate, GLint ycoordinate)
{
    glBegin(GL_POINTS);
    glVertex2i(xcoordinate,ycoordinate);
    glEnd();
    glFlush();
}


//rendering code
void OnDisplay() {
	//set the background color to white
    glClearColor(1,1,1,0);
	//fill the whole color buffer with the clear color
    glClear(GL_COLOR_BUFFER_BIT);
	SetTransformations();

    glColor3f(0,0,0);

    int x = 0;
    int y = radius;
    int p = 1 - radius;

    linePlot(0,0,0,radius);
    linePlot(0,0,0,-radius);
    linePlot(0,0,radius,0);
    linePlot(0,0,-radius,0);

    glBegin(GL_POINTS);

    while (x <= y) {

        glVertex2i(x_center + x, y_center + y);
    //    glVertex2i(x_center - x, y_center + y);
    //    glVertex2i(x_center + x, y_center - y);
        glVertex2i(x_center - x, y_center - y);
    //   glVertex2i(x_center + y, y_center + x);
        glVertex2i(x_center - y, y_center + x);
        glVertex2i(x_center + y, y_center - x);
     //   glVertex2i(x_center - y, y_center - x);

        if (p < 0) {
            p += 2 * x + 3;
        } else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);

    linePlot(0,0,x_center - x, y_center + y);
    linePlot(0,0,x_center + x, y_center - y);
    linePlot(0,0,x_center + y, y_center + x);
    linePlot(0,0,x_center - y, y_center - x);





    glFlush();
}
