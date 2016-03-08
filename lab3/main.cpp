#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;

#define kWIN_WIDTH 640.0f
#define kWIN_HEIGHT 640.0f
#define PI 3.1416


void simpleInit(){
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glColor3f( 1.0, 1.0, 1.0 );
    glPointSize( 3.0 );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


void setWindow(float left, float right, float bottom, float top)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);
}


float kochX[] = {0.0f, .33333f, .5000f, .66666f, 1.0f };
float kochY[] = {0.5f, .50000f, .7886f, .50000f, 0.5f };

int kochLen = 5;


void drawFlake(){
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < kochLen; ++i){
        glVertex3f(kochX[i] - .5f, kochY[i] -.5f, 0.0f);
    }
    glEnd();
}

void displayAtGen(int n ){
    if (n < 0 ) return;
    if (n == 0) {
        drawFlake();

    }
    else {
        drawFlake();
        glScalef(.33333, .33333, .3333f);

        glRotatef(60, 0, 0, 1.0);
        glTranslatef(cos(PI/3)/2, sin(PI/3)/2, 0);
        displayAtGen(n-1);

        glTranslatef(-cos(PI/3)/2, -sin(PI/3)/2, 0);

        glRotatef(-120, 0, 0, 1.0);
        glTranslatef(-cos(PI/3)/2, sin(PI/3)/2, 0);
        displayAtGen(n-1);

        glTranslatef(cos(PI/3)/2, -sin(PI/3)/2, 0);

        glRotatef(60, 0, 0, 1.0);


        float xTranslate = 3*(1.0/6.0 + (.5 - 1.0/6.0)/2);
        glTranslatef(xTranslate, 0.0f, 0.0f );
        displayAtGen(n-1);
        glTranslatef(-2*xTranslate, 0.0f, 0.0f );
        displayAtGen(n-1);
        glTranslatef(xTranslate, 0.0f, 0.0f );

        glScalef(3, 3, 3);
    }
}

void flakeDisplay(void){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1.0f, 1.0f, 1.0f);
    glViewport(0, 0, kWIN_WIDTH, kWIN_HEIGHT);
    setWindow(-.5, .5, -.5, .5);

    float scaleRate = sqrt(3) / 6;

    glScalef(.7, .7 ,.7);
    for (int i = 0; i < 3; i++){

        glTranslatef(0, scaleRate, 0);
        displayAtGen(5);
        glTranslatef(0, -scaleRate, 0);
        glRotatef(120.0f, 0, 0, 1.0f);
    }
    glFlush();
    glutSwapBuffers();
}

int main( int argc, char *argv[] )  {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( kWIN_WIDTH, kWIN_WIDTH );

    glutInitWindowPosition( 700, 0 );
    glutCreateWindow( "lab3_flake");
    glutReshapeWindow(kWIN_WIDTH, kWIN_HEIGHT);

    simpleInit();
    glutDisplayFunc(flakeDisplay);

    glutMainLoop( );

}
