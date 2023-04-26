#include <iostream>
#include <gl\glut.h>
#include <math.h>
#include <ctime>
using namespace std;


float  m, x_1, x_2, y_1 ,y_2;


//Creates the main window
void InitGraphics(int argc, char *argv[]);


//Sets the logical coordinate system
void SetTransformations();


int sgn(float );

void setPixel(GLint , GLint );

//rendering code
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

int sgn(float a){

    if(a==0)
        return 0;

    if(a<0)
        return -1;

    return 1;
}
//rendering code
void OnDisplay() {
	//set the background color to white
    glClearColor(0,0,0,0);
	//fill the whole color buffer with the clear color
    glClear(GL_COLOR_BUFFER_BIT);

	SetTransformations();


// slope intercept
/*
	m=(y_2-y_1)/(x_2-x_1);

	int x,y;
    for(x=1;x<=x_2;x++)

    {

        y=m*(x-x_1)+y_1;

        setPixel(x,y);

    }

*/

	//DDA
  float dy,dx, length;

    dy = y_2 - y_1;
    dx = x_2 - x_1;

    if(abs(dx)>=abs(dy)){

        length = abs(dx);

    }
    else{
        length = abs(dy);
    }

    float xin,yin;

    xin = (x_2-x_1)/length;
    yin = (y_2-y_1)/length;

    float x,y;

    x = x_1 + 0.5 * sgn(xin);
    y = y_1 + 0.5 * sgn(yin);

    int i = 0;
    while(i<=length){


        setPixel(x,y);

        x = x + xin;
        y = y + yin;
        i++;
    }


    glFlush();
}
