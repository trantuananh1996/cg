#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>
#include <iostream>

using namespace std;

float ex, ey, ez;


int nv, np;
float v[2000][3];
int p[3000][3];



void myInit( void )  {
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    ex = -3.2;
    ey = 0;
    ez = 14.4;
    gluPerspective(90, 640/480, .1, 50.0);
}

void loadFace(){
    ifstream fi("face.dat");
    fi>>nv;
    for (int i = 0; i< nv; ++i){
        fi>>v[i][0]>>v[i][1]>>v[i][2];
    }
    fi>>np;
    for (int i = 0 ; i < np; ++i){
        fi>>p[i][0]>>p[i][1]>>p[i][2];
    }

    cout<<nv<<" "<<np;
    fi.close();
}

void drawFace(){
    glBegin(GL_POINTS);
    for (int i = 0; i < nv; ++i){
        glVertex3f(v[i][0], v[i][1], v[i][2]);
    }
    glEnd();
}


void myDisplay( void )  {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
    gluLookAt(ex, ey, ez, 0, 0, 0, 0, 1, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize( 3.0 );

    drawFace();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    float speed = .8;
    switch (key){
    case 'q' : ex+=speed; break;
    case 'Q' : ex-=speed; break;
    case 'w' : ey+=speed; break;
    case 'W' : ey-=speed; break;
    case 'e' : ez+=speed; break;
    case 'E' : ez-=speed; break;
    default: break;
    }
    cout <<ex <<" "<<ey <<" "<<ez<<endl;
    glutPostRedisplay();
}

int main( int argc, char *argv[] )  {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 640, 480 );
    glutInitWindowPosition( 100, 150 );
    glutCreateWindow( "lab7" );


    myInit( );
    loadFace();
    glutDisplayFunc( myDisplay );
    glutKeyboardFunc(keyboard);
    glutMainLoop( );
}


