#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Parts.h"

const int count = 5;
Part* body[count];

void myInit( void )  {

    // gl init
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glColor3f( 1.0, 1.0, 1.0 );
    glPointSize( 3.0 );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    // parts init

    body[0] = new BodyPart();
    body[1] = new ArmPart(body[0]);
    body[2] = new HandPart(body[1]);
    body[3] = new ArmPart(body[0], .9);
    body[4] = new HandPart(body[3], .9);
    body[5] = new UpLeg(body[0]);
    body[6] = new LowLeg(body[5]);
    body[7] = new UpLeg(body[0], .9);
    body[8] = new LowLeg(body[7], .9);

}

void drawPart(Part* part){
    glBegin(GL_LINES);
    glVertex3f(part->head.x, part->head.y, .0);
    glVertex3f(part->getTail().x, part->getTail().y, .0);
    glEnd();
}


void stickmanDisplay( void )  {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1.0f, 1.0f, 1.0f);


    for (int i = 0; i < 9; i++){
        body[i]->tick(6e-4);
        drawPart(body[i]);
    }

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}



int main( int argc, char *argv[] )  {  
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 640, 480 );
    glutInitWindowPosition( 100, 150 );
    glutCreateWindow( "lab1" );


    myInit( );
    glutDisplayFunc( stickmanDisplay );

    glutMainLoop( );
}


