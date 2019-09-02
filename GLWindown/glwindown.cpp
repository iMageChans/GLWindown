#include "glwindown.h"
#include "ggl.h"
#include "utils.h"
#include "skybox.h"

skybox box;

GLWindown::GLWindown(QWidget *parent)
    : QGLWidget(parent)
{
}

void GLWindown::initializeGL(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    loadGLTextures();

}

void GLWindown::resizeGL(int w, int h){
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0,1920.0/1080.0,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
}


void GLWindown::paintGL(){
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    box.Darw();
    glEnable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);
    glColor4ub(0,50,200,255);
    glVertex3f(-0.1f, -0.1f, 0.6f);
    glVertex3f(0.1f, -0.1f, 0.6f);
    glVertex3f(0.1f, 0.1f, 0.6f);
    glVertex3f(-0.1f, 0.1f, 0.6f);
    glEnd();
}

void GLWindown::loadGLTextures(){
    const char* imageDir[6];
    imageDir[0] = ":/new/prefix/back.bmp";
    imageDir[1] = ":/new/prefix/bottom.bmp";
    imageDir[2] = ":/new/prefix/front.bmp";
    imageDir[3] = ":/new/prefix/left.bmp";
    imageDir[4] = ":/new/prefix/right.bmp";
    imageDir[5] = ":/new/prefix/top.bmp";

    box.Init(imageDir, texture);
}
