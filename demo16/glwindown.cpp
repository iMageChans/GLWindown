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
    glMatrixMode(GL_PROJECTION);
    gluPerspective(50.0,800.0f/600.0f,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
}


void QLWindown::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -5.0f);
        glPushMatrix();
        glRotatef(30.f,0.0f,1.0f,0.0f);
        glBegin(GL_TRIANGLES);
        glColor4ub(255,0,0,255);glVertex3f(-0.5f,-0.25f,0.0f);
        glColor4ub(0,0,255,255);glVertex3f(0.5f,-0.25f,0.0f);
        glColor4ub(0,255,0,255);glVertex3f(0.0f,0.5f,0.0f);
        glEnd();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glRotatef(30.f,0.0f,1.0f,0.0f);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -5.0f);
        glBegin(GL_TRIANGLES);
        glColor4ub(255,0,0,255);glVertex3f(-0.5f,-0.25f,0.0f);
        glColor4ub(0,0,255,255);glVertex3f(0.5f,-0.25f,0.0f);
        glColor4ub(0,255,0,255);glVertex3f(0.0f,0.5f,0.0f);
        glEnd();
        glPopMatrix();
    glPopMatrix();
}
