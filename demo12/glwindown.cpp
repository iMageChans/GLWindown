#include "glwindown.h"
#include <glu.h>

QLWindown::QLWindown(QWidget *parent)
    : QGLWidget(parent)
{
}

void QLWindown::initializeGL(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
}

void QLWindown::resizeGL(int w, int h){
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(GLfloat)w/(GLfloat)h,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void QLWindown::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(30.0f, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);
    glColor4ub(255,0,0,255);glVertex3f(-0.5f,-0.25f,-2.5f);
    glColor4ub(0,0,255,255);glVertex3f(0.5f,-0.25f,-2.5f);
    glColor4ub(0,255,0,255);glVertex3f(0.0f,0.5f,-2.5f);
    glEnd();
}
