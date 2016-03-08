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
#define kWIN_HEIGHT 480.0f

#define XMIN -400.0
#define XMAX 400.0

#define kF1_SCALE_X 10
#define kF1_SCALE_Y .3

#define kF2_SCALE_X 10.0
#define kF2_SCALE_Y 5


int pathCount;
int dinQ[50];
float dinX[500], dinY[500];

void loadModel(const char* fileName, int &count, int q[],
               float x[], float y[]){
  ifstream fi(fileName);
  fi>>count;
  for (int i = 0; i < count ; ++i){
      float pathLen;
      fi>>pathLen;
      int lastLen = i == 0 ? 0 : q[i-1];
      q[i] = pathLen + lastLen;

      for (int j = 0; j < pathLen; ++j){
          int pos = lastLen + j + 1;
          fi >> x[pos]>> y[pos];
        }
    }

  fi.close();
}

void simpleInit(){
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  glColor3f( 1.0, 1.0, 1.0 );
  glPointSize( 3.0 );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void dinoInit( void )  {
  simpleInit();
  loadModel("dinosaur.dat", pathCount, dinQ, dinX, dinY);
}


void drawDinosaur(){
  for (int i = 0; i < pathCount; ++i){
      int u = i == 0 ? 0 : dinQ[i-1];
      int v = dinQ[i];
      glBegin(GL_LINE_STRIP);
      for (int j = u+1; j <= v; ++j){
          glVertex3f(dinX[j]*(kWIN_WIDTH/640.0f)*.7,
                     dinY[j]*(kWIN_HEIGHT/480.0f)*.7, 0);
        }
      glEnd();
    }
}

void setWindow(float left, float right, float bottom, float top)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(left, right, bottom, top);
}


void dinosaurDisplay(void ){
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glColor3f(1.0f, 1.0f, 1.0f);

	for (int i = 0; i < 5; ++i){
      for (int j = 0; j < 5; ++j){
          glViewport(kWIN_WIDTH * i / 5.0f,
                     kWIN_HEIGHT * j / 5.0f,
                     kWIN_WIDTH / 5.0f,
                     kWIN_HEIGHT / 5.0f);

          float md =(float) ((i+j) % 2);
          setWindow(0,kWIN_WIDTH,
                    md * kWIN_HEIGHT,
                    (1-md) * kWIN_HEIGHT);
          drawDinosaur();
        }
    }


  glFlush();
  glutSwapBuffers();
}

void functionDisplay(void){
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glColor3f(1.0f, 1.0f, 1.0f);
  glViewport(0, 0, kWIN_WIDTH, kWIN_HEIGHT);

  setWindow(-kWIN_WIDTH / 2.0, kWIN_WIDTH / 2.0,
            -kWIN_HEIGHT / 2.0, kWIN_HEIGHT / 2.0);

  // y = x^3 + 2*x^2 + 3
  float delta = .2;
  glBegin(GL_LINE_STRIP);
    for (float x = XMIN; x < XMAX; x+= delta){
      float y = x*x*x + 2*x*x + 3;
      glVertex3f(x * kF1_SCALE_X, y * kF1_SCALE_Y, 0);
    }
  glEnd();


  // y = 2*sin(x) + .5*cos(x)
  glColor3f(1.0f, 0.0f, 0.0f);
  glBegin(GL_LINE_STRIP);
    for (float x = XMIN; x < XMAX; x += delta){
      float y = 2.0f*sin(x) + .5f*cos(x);
      glVertex3f(x * kF2_SCALE_X, y * kF2_SCALE_Y, 0);
    }
  glEnd();


  glFlush();
  glutSwapBuffers();
}

int main( int argc, char *argv[] )  {
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowSize( kWIN_WIDTH, kWIN_WIDTH );


  glutInitWindowPosition( 0, 0 );
  glutCreateWindow( "lab2_dinosaur" );
 	glutReshapeWindow(kWIN_WIDTH, kWIN_HEIGHT);
  dinoInit( );
  glutDisplayFunc( dinosaurDisplay );

  glutInitWindowPosition( 700, 0 );  
  glutCreateWindow( "lab2_function" );
 	glutReshapeWindow(kWIN_WIDTH, kWIN_HEIGHT);
  simpleInit();
  glutDisplayFunc(functionDisplay);


  glutMainLoop( );

}
