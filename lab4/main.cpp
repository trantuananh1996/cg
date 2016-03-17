#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define kDELTA_T .1



/*
 * Press 'a' and 'd' to tween
 *
 *
 * */

const int len = 3;
float house[] = {.1, .1, .1, .5, .5, .1};
float car[] =   {.2, .2, .3, .4, .7, .8};


float t = 0.0;



void simpleInit( void )  {
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	glColor3f( 1.0, 1.0, 1.0 );
	glPointSize( 3.0 );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}



void myDisplay( void )  {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
		for (int i = 0; i < len; i++){
			int x = 2*i;
			int y = x + 1;
			glVertex2d(house[x] + t*(car[x] - house[x])
								,house[y] + t*(car[y] - house[y])) ;
		}
	glEnd();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y){
	if (key == 'a'){
		t = std::max(0.0, t-kDELTA_T);
	}

	if (key == 'd'){
		t = std::min(1.0,t +kDELTA_T);
	}

}




int main( int argc, char *argv[] )  {
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize( 640, 480 );
	glutInitWindowPosition( 100, 150 );
	glutCreateWindow( "lab4" );

	simpleInit( );
	glutDisplayFunc( myDisplay );
	glutKeyboardFunc(keyboard);
	glutMainLoop( );
}

