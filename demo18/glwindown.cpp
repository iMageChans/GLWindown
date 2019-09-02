#include "glwindown.h"
#include "ggl.h"
#include "utils.h"

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
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(-0.1f,-0.1f,-0.4f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(0.1f,-0.1f,-0.4f);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(0.1f,0.1f,-0.4f);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(-0.1f,0.1f,-0.4f);
    glEnd();
}

void GLWindown::loadGLTextures(){
    QImage tex, buf;
    buf.load( ":/img/timg.bmp");
    tex = QGLWidget::convertToGLFormat(buf);
    glBindTexture( GL_TEXTURE_2D, texture);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

}
