#include <iostream>
#include <gl\glut.h>
#include <math.h>
#include <ctime>
using namespace std;

float  x_1, x_2, y_1 ,y_2;

void setPixel(GLint , GLint );


//Creates the main window
void InitGraphics(int argc, char *argv[]);


//Sets the logical coordinate system
void SetTransformations();


void OnDisplay();


int main(int argc, char* argv[]) {
      cout<<"X1 = "; cin>>x_1; cout<<"Y1 = "; cin>>y_1; cout<<"X2 = "; cin>>x_2;  cout<<"Y2 = "; cin>>y_2;
    InitGraphics(argc, argv);

	return 0;

}



void InitGraphics(int argc, char *argv[]) {
	glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,400);
	glutInitWindowPosition(400, 100);

	glutCreateWindow("OpenGL Assignment1");
	SetTransformations();
	//OnDisplay will handle the paint event
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
}


void SetTransformations() {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-800, 800, -800, 800);

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
    glClearColor(0,0,0,0);
	//fill the whole color buffer with the clear color
    glClear(GL_COLOR_BUFFER_BIT);

	SetTransformations();

	//bresenham
	GLint dx = x_2-x_1;
    GLint dy = y_2-y_1;
    GLint steps,k;
    steps=dx;
    GLint x,y,p0=(2*dy)-dx;
    setPixel(x_1,y_1);
    x=x_1;
    y=y_1;
    for(k=0;k<steps;k++)
    {
        if(p0<0)
        {
            p0=p0+(2*dy);
            x+=1;
        }
        else
        {
            p0=p0+(2*dy)-(2*dx);
            x+=1;
            y+=1;
        }
        setPixel(x,y);
    }


    glFlush();
}
