#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Stick.h"


Stick *body;

const int len = 9;
Stick* human[len];

void stickmanInit( void )  {    
    glClearColor( 0.0, 0.0, 0.0, 0.0 );        
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    human[0] = new Stick(SR_BODY);
    human[1] = new Stick(SR_HAND_UPPER, human[0]);
    human[2] = new Stick(SR_HAND_UPPER, human[0], .9);
    human[3] = new Stick(SR_HAND_LOWER, human[1]);
    human[4] = new Stick(SR_HAND_LOWER, human[2], .9);
    human[5] = new Stick(SR_FOOT_UPPER, human[0]);
    human[6] = new Stick(SR_FOOT_UPPER, human[0], .9);
    human[7] = new Stick(SR_FOOT_LOWER, human[5]);
    human[8] = new Stick(SR_FOOT_LOWER, human[6], .9);
}

void drawStick(Stick* stick){
    glBegin(GL_LINES);
    glVertex3f(stick->head.x, stick->head.y, .0);
    glVertex3f(stick->tail().x, stick->tail().y , .0);
    glEnd();
}

void stickmanDisplay( void )  {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1.0f, 1.0f, 1.0f);

    for (int i = 0; i < len; ++i){
        human[i]->tick(5e-4);
        drawStick(human[i]);
    }

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glPopMatrix();
    //glTranslatef(.5*w, .5*h, 0);
}



int main( int argc, char *argv[] )  {  
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 640, 480 );
    glutInitWindowPosition( 100, 150 );
    glutCreateWindow( "lab6" );
    stickmanInit( );
    glutDisplayFunc( stickmanDisplay );

    glutMainLoop( );
}
