#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


void myInit( void )  {
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  glColor3f( 1.0, 1.0, 1.0 );
  glPointSize( 3.0 );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

  srand (time(NULL));
}

// get random number in [0,1]
float getRand(){
  return (float) rand() / RAND_MAX;
}

void myDisplay( void )  {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );





  // A house
  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_LINE_STRIP);
    glVertex3f(0.25, 0.75, 0.0);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glVertex3f(0.50, 0.90, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
  glEnd();
    //the door
  glBegin(GL_LINE_STRIP);
  glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.42, 0.25, 0.0);
    glVertex3f(0.42, 0.55, 0.0);
    glVertex3f(0.58, 0.55, 0.0);
    glVertex3f(0.58, 0.25, 0.0);
  glEnd();




  // Three dots
  // gerenate random numbers


  glBegin(GL_POINTS);
  glColor3f(1.0f, 0.0f, 0.0f);
  for (int i = 0; i < 3; i++)
    glVertex3f(getRand(), getRand(), 0.0);

  glEnd();


  glFlush();
  glutSwapBuffers();

}

/* ----------------------------------------------------------------------- */

int main( int argc, char *argv[] )  {
  // Initialize GLUT.
  glutInit( &argc, argv );
  // Set the mode to draw in.
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  // Set the window size in screen pixels.
  glutInitWindowSize( 640, 480 );
  // Set the window position in screen pixels.
  glutInitWindowPosition( 100, 150 );
  // Create the window.
  glutCreateWindow( "lab1" );
  // Set the callback funcion to call when we need to draw something.


  myInit( );
  glutDisplayFunc( myDisplay );
  // Initialize some things.
  // Now that we have set everything up, loop responding to events.
  glutMainLoop( );
}

/* ----------------------------------------------------------------------- */
