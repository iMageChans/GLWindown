#include "glwindown.h"
#include "ggl.h"
#include "utils.h"

GLWindown::GLWindown(QWidget *parent)
    : QGLWidget(parent)
{
}

void GLWindown::initializeGL(){
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    loadGLTextures();

}

void GLWindown::resizeGL(int w, int h){
    glMatrixMode(GL_PROJECTION);
    gluPerspective(50.0f, 800.0f/600.0f, 0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}


void GLWindown::paintGL(){
    glLoadIdentity();
    glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -0.1f, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 0.1f, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 0.1f, -0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -0.1f, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 0.1f, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 0.1f, 0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, -0.1f, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -0.1f, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 0.1f, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 0.1f, -0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, 0.1f, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, 0.1f, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 0.1f, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 0.1f, 0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -0.1f, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, -0.1f, -0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, -0.1f, -0.5f);
    glEnd();

//    glEnable(GL_DEPTH_TEST);
//    glBegin(GL_QUADS);
//    glColor4ub(255,255,255,255);
//    glVertex3f(-0.1f, -0.1f, -0.6f);
//    glVertex3f(0.1f, -0.1f, -0.6f);
//    glVertex3f(0.1f, 0.1f, -0.6f);
//    glVertex3f(-0.1f, 0.1f, -0.6f);
//    glEnd();

}

void GLWindown::loadGLTextures(){

//    GLuint textures;

    const char* imageDir[6];
    imageDir[0] = ":/new/prefix/back.bmp";
    imageDir[1] = ":/new/prefix/bottom.bmp";
    imageDir[2] = ":/new/prefix/front.bmp";
    imageDir[3] = ":/new/prefix/left.bmp";
    imageDir[4] = ":/new/prefix/right.bmp";
    imageDir[5] = ":/new/prefix/top.bmp";

//    for(int i = 0; i < 6; i ++){
//        QImage tex, buf;
//        buf.load(imageDir[i]);
//        tex = QGLWidget::convertToGLFormat(buf);
//        glGenTextures(1, &texture);
//        glBindTexture(GL_TEXTURE_2D, texture);
//        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, tex.width(), tex.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, tex.bits());
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//        glBindTexture(GL_TEXTURE_2D, 0);
//    }

    textures[0] = 1;
    textures[1] = 2;
    textures[2] = 3;
    textures[3] = 4;
    textures[4] = 5;
    textures[5] = 6;

    QImage tex1, buf1;
    buf1.load(":/new/prefix/back.bmp");
    tex1 = QGLWidget::convertToGLFormat(buf1);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, tex1.width(), tex1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex1.bits());

    QImage tex2, buf2;
    buf2.load(":/new/prefix/bottom.bmp");
    tex2 = QGLWidget::convertToGLFormat(buf2);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, tex2.width(), tex2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex2.bits());

    QImage tex3, buf3;
    buf3.load(":/new/prefix/front.bmp");
    tex3 = QGLWidget::convertToGLFormat(buf3);
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, tex3.width(), tex3.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex3.bits());

    QImage tex4, buf4;
    buf4.load(":/new/prefix/left.bmp");
    tex4 = QGLWidget::convertToGLFormat(buf4);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, tex4.width(), tex4.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex4.bits());

    QImage tex5, buf5;
    buf5.load(":/new/prefix/right.bmp");
    tex5 = QGLWidget::convertToGLFormat(buf5);
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, tex5.width(), tex5.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex5.bits());

    QImage tex6, buf6;
    buf6.load(":/new/prefix/top.bmp");
    tex6 = QGLWidget::convertToGLFormat(buf6);
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, tex6.width(), tex6.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex6.bits());

}
