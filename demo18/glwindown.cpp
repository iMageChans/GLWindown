#include "glwindown.h"
#include <glu.h>

GLWindown::GLWindown(QWidget *parent)
    : QGLWidget(parent)
{
}

void GLWindown::initializeGL(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
}

void GLWindown::resizeGL(int w, int h){
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0,1920.0f/1080.0f,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
}


void GLWindown::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glClearColor(30.0f/255.0f, 30.0f/255.0f, 30.0f/255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_CULL_FACE);

    float lightPos[] = {0.0f, 1.0f, 0.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    float whiteColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float ambientMant[] = {0.07f, 0.07f, 0.07f, 1.0f};
    float diffuseMat[] = {0.4f, 0.4f, 0.4f, 1.0f};
    float specularMat[] = {0.9f, 0.9f, 0.9f, 1.0f};
    float blackColor[] = {0.0f, 0.0f, 0.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMant);

    glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMat);

    glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMat);

    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glVertex3f(-0.5f, -0.2f, -0.5f);
    glVertex3f(0.5f, -0.2f, -0.5f);
    glVertex3f(0.5f, -0.2f, -1.0f);
    glVertex3f(-0.5f, -0.2f, -1.0f);
    glEnd();
}

unsigned char* GLWindown::LoadFile(const char* path, int &filesize){
    unsigned char* fileContent = nullptr;
    filesize = 0;
    FILE *pFile = fopen(path, "rb");
    if (pFile){
        fseek(pFile, 0, SEEK_END);
        int nLen = ftell(pFile);
        if (nLen > 0){
            rewind(pFile);
            fileContent = new unsigned char(nLen + 1);
            fread(fileContent, sizeof(unsigned char), nLen, pFile);
            fileContent[nLen] = '\0';
            filesize = nLen;
        }
        fclose(pFile);
    }
    return fileContent;
}
