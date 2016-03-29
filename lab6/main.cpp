#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "BodyPart.h"
#include <cstdio>

BodyPart lhand, rhand;
BodyPart body;
BodyPart lfoot, rfoot;



void myInit( void )  {
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  glColor3f( 1.0, 1.0, 1.0 );
  glPointSize( 3.0 );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void tickBodyPart(BodyPart *part);

void myDisplay( void )  {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glColor3f(1.0f, 1.0f, 1.0f);

  tickBodyPart(&hand);

  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

void tickBodyPart(BodyPart *part){
    part->tick(5e-4);

    Vec2 line[2];
    part->getLine(line);
    glBegin(GL_LINES);

    glVertex3f(line[0]._x, line[0]._y, .0);
    glVertex3f(line[1]._x, line[1]._y, .0);

    glEnd();
}

int main( int argc, char *argv[] )  {
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowSize( 640, 480 );
  glutInitWindowPosition( 100, 150 );
  glutCreateWindow( "lab1" );


  myInit( );
  glutDisplayFunc( myDisplay );

  glutMainLoop( );
}
