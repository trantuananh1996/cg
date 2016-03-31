#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>


float ex = 5;
float ey = 5;
float ez = 5;


float cx, cy, cz;// center of the objects


void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_FLAT);
    cx = cy = cz = 2;
}

void dline(float x, float y, float z, float r, float g, float b){
    glColor3f(r, g, b);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(x, y, z);
    glEnd();
    glLineWidth(1);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    dline(10,0, 0, 1, 0, 0);
    dline(0, 10,0, 0, 1, 0);
    dline(0, 0, 10, 0, 0, 1);

    glTranslatef (2, 2, 2);

    glColor3f (1.0, 0, 0);
    glutWireSphere(1.0, 20, 16);

    glColor3f (0, 0, 1.0);
    glutWireCube(3.0f);

    glPopMatrix();
    glutSwapBuffers();
}
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(100.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glPopMatrix();
    glPushMatrix();
    gluLookAt (ex, ey, ez,
               cx, cy, cz,
               0, 1, 0);
}

void keyboard (unsigned char key, int x, int y)
{

    float speed = 5e-1;
    switch (key) {
    case 'w':
        ey += speed;
        cy += speed;
        break;
    case 's':
        ey -= speed;
        cy -= speed;
        break;
    case 'a':
        ex -= speed;
        cx -= speed;
        break;
    case 'd':
        ex += speed;
        cx += speed;
        break;
    }




    glPopMatrix();
    glPushMatrix();


    gluLookAt (ex, ey, ez, cx, cy, cz, 0.0, 1.0, 0.0);
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
