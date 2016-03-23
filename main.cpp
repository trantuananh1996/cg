#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void myInit( void )  {
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  glColor3f( 1.0, 1.0, 1.0 );
  glPointSize( 3.0 );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

  srand (time(NULL));
}


void myDisplay( void )  {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glColor3f(1.0f, 1.0f, 1.0f);

  glFlush();
  glutSwapBuffers();

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


