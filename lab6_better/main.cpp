#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Camera.h"
#include "Stick.h"

float ex = 5;
float ey = 5;
float ez = 5;

float cx, cy, cz;// center of the objects

Camera * cam;

void updateCamera();

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_FLAT);
    cam = Camera::getInstance();
    glViewport (0, 0, 500, 500);
    cx = cy = cz = 0;

    gluLookAt(5, 5, 5, 2, 2, 2, 0, 1, 0);

}


void dline(float x, float y, float z, float r, float g, float b){
    glColor3f(r, g, b);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(x, y, z);
    glEnd();
    glLineWidth(1);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    cam->updateCamera();
    dline(1,0, 0, 1, 0, 0);
    dline(0, 1,0, 0, 1, 0);
    dline(0, 0, 1, 0, 0, 1);


    glTranslatef(0, 1, 0);
    glColor3f (1.0, 0, 0);
    glutWireSphere(1.0, 20, 16);

    glColor3f (.1, .6, .8);
    glutWireCube(3.0f);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(80.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();    
}

void keyboard (unsigned char key, int x, int y)
{    

    float speed = 1;
    switch (key) {
    case 'w':
        cam->onChangeAxis(0, speed);
        break;
    case 's':
        cam->onChangeAxis(0, -speed);
        break;
    case 'a':
        cam->onChangeAxis(-speed, 0);
        break;
    case 'd':        
        cam->onChangeAxis(speed, 0);
        break;
    }
    glutPostRedisplay();
}




int main(int argc, char** argv)
{

    glutInit(&argc, argv);


    Stick::ShowStickMan();


    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("lab6 (w/s/a/d to move the camera)");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
