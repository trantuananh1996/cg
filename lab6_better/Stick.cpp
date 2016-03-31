#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Stick.h"

const int len = 9;
Stick* human[len];

void drawStick(Stick* stick){
    glBegin(GL_LINES);
    glVertex3f(stick->head.x, stick->head.y, .0);
    glVertex3f(stick->tail().x, stick->tail().y , .0);
    glEnd();
}

void stickmanDisplay( void )  {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1.0f, 1.0f, 1.0f);

    for (int i = 0; i < len; ++i){
        human[i]->tick(5e-4);
        drawStick(human[i]);
    }

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void stickmanInit()  {
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    human[0] = new Stick(SR_BODY);
    human[1] = new Stick(SR_HAND_UPPER, human[0]);
    human[2] = new Stick(SR_HAND_UPPER, human[0], .9);
    human[3] = new Stick(SR_HAND_LOWER, human[1]);
    human[4] = new Stick(SR_HAND_LOWER, human[2], .9);
    human[5] = new Stick(SR_FOOT_UPPER, human[0]);
    human[6] = new Stick(SR_FOOT_UPPER, human[0], .9);
    human[7] = new Stick(SR_FOOT_LOWER, human[5]);
    human[8] = new Stick(SR_FOOT_LOWER, human[6], .9);
}

void Stick::ShowStickMan(){
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 640, 480 );
    glutInitWindowPosition( 100, 150 );
    glutCreateWindow( "lab6_StickMan" );
    stickmanInit( );
    glutDisplayFunc( stickmanDisplay );
}
Vec2 Stick::tail(){
    return Vec2(head.x + cos(angle)* len,
                head.y + sin(angle) * len);
}

Stick::Stick(StickRole role, Stick *pPar, float delay){
    this->role = role;
    parent = pPar;
    time = delay;
    digit = 1;
    angle = 0;

    tick(0.0);
}

float Stick::ratio(){
    return time/roundTime;
}


void Stick::tick(float dt){
    time += digit * dt;
    switch (role){
    case SR_BODY:{
        roundTime = 4.0f;
        len = .3;

        angle = -PI/2;
        head = Vec2(.2 + .6 * ratio(), .6);


        break;
    }
    case SR_HAND_UPPER:{
        roundTime = 1.0f;
        len = .1;

        head = parent->head;
        angle = 1.4 * PI + PI*.2f * ratio();
        break;
    }
    case SR_HAND_LOWER:{
        roundTime = 1.0f;
        len = .05;

        head = parent->tail();
        angle = parent->angle + PI*.2f * ratio();
        break;
    }
    case SR_FOOT_UPPER:{
        roundTime = 1.0f;
        len = .1;

        head = parent->tail();
        angle = parent->angle - .05*PI + PI*.15f * ratio();
        break;
    }
    case SR_FOOT_LOWER:{
        roundTime = 1.0;
        len = .1;

        head= parent->tail();
        angle = parent->angle + .02*PI - PI*.17f * ratio();
        break;
    }
    }

    digit = time > roundTime ? -1 : digit;
    digit = time < 0 ? 1 : digit;
}
