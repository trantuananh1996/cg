#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstring>
#include <algorithm>
#include <cstdio>



enum TransformMode{
	TM_TRANS = 0,
	TM_ROTATE,
	TM_SCALE
};


int len = 16;
float house[] = {.0, .5, .5, 1.,
								 .7, .8, .7, .9,
								 .8, .9, .8, .9,
								 .8, .7, 1., .5,
								 .8, .5, .8, .0,
								 .6, .0, .6, .2,
								 .4, .2, .4, .0,
								 .2, .0, .2, .5};

TransformMode currentMode = TM_TRANS;



#define kDELTA_T .05
float gTx = .0, gTy = .0;

#define kDELTA_R 1.5
float gRotate = .0;

#define kDELTA_S .1
float gScaleX = 1.0f;
float gScaleY = 1.0f;


void myInit( void )  {
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  glColor3f( 1.0, 1.0, 1.0 );
  glPointSize( 3.0 );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

}

void displayText( float x, float y,  const char *string,
									int r  = 255, int g = 255, int b = 255) {
	int j = strlen( string );

	glColor3f( r, g, b );
	glRasterPos2f( x, y );
	for( int i = 0; i < j; i++ ) {
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, string[i] );
	}
}



void  drawHouse(){
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < len; i++){
		glVertex2f(house[i<<1], house[(i<<1) + 1]);
	}
	glEnd();
}


void myDisplay( void )  {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();
	glTranslatef(gTx, gTy, .0f);
	glRotatef(gRotate, 0.0, 0.0, 1.0);
	glScalef(gScaleX, gScaleY, 1.0);
	drawHouse();
	glPopMatrix();

// show help text
	displayText(.0,.07, "Press Q to change mode");
	switch (currentMode){
	case TM_TRANS:{
		displayText(.0,.01, "Current Mode : translate (w/s/a/d to move)" );
		break;
	}
	case TM_ROTATE:{
		displayText(.0,.01, "Current Mode : rotate (a/d to rotate)" );
		break;
	}
	case TM_SCALE:{
		displayText(.0,.01, "Current Mode : scale (w/s/a/d to scale)" );
	}
	default: break;
	}

  glFlush();
  glutSwapBuffers();


}



void keyboard (unsigned char key, int x, int y){
	if (key == 'q'){
		currentMode = (TransformMode)((currentMode + 1) % 3);
	}


	if (currentMode == TM_TRANS){
		switch(key){
		case 'w' : gTy += kDELTA_T; break;
		case 's' : gTy -= kDELTA_T; break;
		case 'a' : gTx -= kDELTA_T; break;
		case 'd' : gTx += kDELTA_T; break;
		}

	}

	if (currentMode == TM_ROTATE){
		switch(key){
		case 'a' : gRotate -= kDELTA_R; break;
		case 'd' : gRotate += kDELTA_R; break;
		}
	}

	if (currentMode == TM_SCALE){
		switch(key){
		case 'w' : gScaleY += kDELTA_S; break;
		case 's' : gScaleY -= kDELTA_S; break;
		case 'a' : gScaleX -= kDELTA_S; break;
		case 'd' : gScaleX += kDELTA_S; break;
		}
	}
	glutPostRedisplay();

}

int main( int argc, char *argv[] )  {  
  glutInit( &argc, argv );  
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );  
  glutInitWindowSize( 640, 480 );  
  glutInitWindowPosition( 100, 150 );  
	glutCreateWindow( "lab5" );


	myInit( );
  glutDisplayFunc( myDisplay );
	glutKeyboardFunc(keyboard);


  glutMainLoop( );
}


