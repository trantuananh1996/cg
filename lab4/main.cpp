#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define kDELTA_T .1


const int len = 16;
float house[] = {.0, .5, .5, 1.,
                 .7, .8, .7, .9,
                 .8, .9, .8, .9,
                 .8, .7, 1., .5,
                 .8, .5, .8, .0,
                 .6, .0, .6, .2,
                 .4, .2, .4, .0,
                 .2, .0, .2, .5
                 };

float car[] =   {.0, .3, .1, .3,
                 .2, .6, .6, .6,
                 .9, .3, 1., .3,
                 1., .0, .8, .0,
                 .7, .1, .6, .1,
                 .6, .0, .4, .0,
                 .3, .1, .2, .1,
                 .1, .0, .0, .0
                };


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
	glutCreateWindow( "lab4 : Press 'a' or 'd' to tween" );

	simpleInit( );
	glutDisplayFunc( myDisplay );
	glutKeyboardFunc(keyboard);
	glutMainLoop( );
}

