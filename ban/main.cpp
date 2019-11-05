#include <iostream>
#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
float angle=5,xpos=-1;

void idle()
  {

angle+=5;

if(xpos<=1)
xpos+=0.0002;
else
xpos=xpos-2;

glutPostRedisplay();
}

void display()

{
     glClearColor(1, 1, 1, 1.0); // white background
     glClear(GL_COLOR_BUFFER_BIT);

	 glPushMatrix();
     glTranslatef(xpos,0,0);
     glRotatef(angle,0,0,1);


     glColor3f(0,0,0); // black foreground
     glScalef(0.1,0.1,0.1);
     glutWireTorus(0.5, 2.0, 30, 30);
     glPopMatrix();

     glutSwapBuffers();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("ban");

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();
}
