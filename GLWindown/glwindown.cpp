#include "glwindown.h"
#include "ggl.h"
#include "utils.h"

GLWindown::GLWindown(QWidget *parent)
    : QGLWidget(parent)
{

}

void GLWindown::initializeGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
    loadGLTextures();
}

void GLWindown::resizeGL(int w, int h){
    glMatrixMode(GL_PROJECTION);
    gluPerspective(50.0f,800.0f/600.0f,0.1f,1000.0f);
    glMatrixMode(GL_MODELVIEW);
}


void GLWindown::paintGL(){
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    box.Darw();
    model.Draw();
}

void GLWindown::loadGLTextures(){
    const char* imageDir[6];
    imageDir[0] = ":/new/prefix/back.bmp";
    imageDir[1] = ":/new/prefix/bottom.bmp";
    imageDir[2] = ":/new/prefix/front.bmp";
    imageDir[3] = ":/new/prefix/left.bmp";
    imageDir[4] = ":/new/prefix/right.bmp";
    imageDir[5] = ":/new/prefix/top.bmp";
    box.Init(imageDir);
    model.Init("/Users/qie/Documents/GLWindown/GLWindown/Res/Sphere.obj");
    model.mTexture = CreateTexture2DFromBMP("/Users/qie/Documents/GLWindown/GLWindown/Res/earth.bmp");
}

const QImage DecodeBMP(const char* bmpPath){
    QImage img, buf;
    buf.load(bmpPath);
    img = QGLWidget::convertToGLFormat(buf);
    return img;
}

unsigned char * LoadFileContent(const char *path, int &filesize) {
    unsigned char*fileContent = nullptr;
    filesize = 0;
    FILE*pFile = fopen(path, "rb");
    if (pFile) {
        fseek(pFile, 0, SEEK_END);
        int nLen = ftell(pFile);
        if (nLen > 0) {
            rewind(pFile);
            fileContent = new unsigned char[nLen + 1];
            fread(fileContent, sizeof(unsigned char), nLen, pFile);
            fileContent[nLen] = '\0';
            filesize = nLen;
        }
        fclose(pFile);
    }
    return fileContent;
}


