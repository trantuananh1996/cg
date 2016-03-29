#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "BodyPart.h"
#include <cstdio>

BodyPart *lhand, *rhand;
BodyPart *body;
BodyPart *lfoot, *rfoot;

void initData(){
    Vec2 bodyLines[] = {Vec2(.5, .3), Vec2(.5, .6)};
    float bodyTime[] = {1.0f};
    body =  new BodyPart(1, bodyLines, bodyTime);

    //hands
    Vec2 lhLines[] = {Vec2(.5, .6), Vec2(.4, .4),
                     Vec2(.5, .6), Vec2(.6, .4)};
    float lhTime[] = {.0, 1.0f};
    lhand =  new BodyPart(2, lhLines, lhTime);

    Vec2 rhLines[] = {Vec2(.5, .6), Vec2(.6, .4),
                     Vec2(.5, .6), Vec2(.4, .4)};
    float rhTime[] = {.0, 1.0f};
    rhand =  new BodyPart(2, rhLines, rhTime);


    //foots
    Vec2 lfLines[] = {Vec2(.5, .3), Vec2(.55, .1),
                     Vec2(.5, .3), Vec2(.45, .1)};
    float lfTime[] = {.0, 1.0f};
    lfoot =  new BodyPart(2, lfLines, lfTime);

    Vec2 rfLines[] = {Vec2(.5, .3), Vec2(.45, .1),
                     Vec2(.5, .3), Vec2(.55, .1)};
    float rfTime[] = {.0, 1.0f};
    rfoot =  new BodyPart(2,rfLines, rfTime);

}



void myInit( void )  {
  glClearColor( 0.0, 0.0, 0.0, 0.0 );
  glColor3f( 1.0, 1.0, 1.0 );
  glPointSize( 3.0 );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
  initData();
}

void tickBodyPart(BodyPart *part);

void myDisplay( void )  {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glColor3f(1.0f, 1.0f, 1.0f);

  tickBodyPart(body);
  tickBodyPart(lhand);
  tickBodyPart(rhand);
  tickBodyPart(lfoot);
  tickBodyPart(rfoot);

  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

void tickBodyPart(BodyPart *part){

    part->tick(5e-4);
    Vec2 line[2];
    part->getLine(line);
    glBegin(GL_LINES);

//    printf("%.2f %.2f  %.2f  %.2f \n", line[0]._x, line[0]._y, line[1]._x, line[1]._y);
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
