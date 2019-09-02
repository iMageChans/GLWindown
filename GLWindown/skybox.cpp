#include "skybox.h"
#include <QGLWidget>
#include "utils.h"

skybox::skybox(QObject *parent) : QObject(parent)
{

}


void skybox::Init(const char* imageDir[], GLuint texture){
    for(int i = 0; i < 6; i++){
        initializeImage(imageDir[i], i, texture);
    }
    mFastDrawCall = CreateDisplayList([this]()->void{ DarwCommand(); });
}

void skybox::DarwCommand(){

    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    setQuadsBack(mTexture[0]);
    setQuadsBottom(mTexture[1]);
    setQuadsFront(mTexture[2]);
    setQuadsLeft(mTexture[3]);
    setQuadsRight(mTexture[4]);
    setQuadsTop(mTexture[5]);

}

void skybox::initializeImage(const char* imageDir, int &index, GLuint texture){
    mTexture[index] = CreateTexture2DFromBMP(imageDir, texture);
}

void skybox::Darw(){
    glCallList(mFastDrawCall);
}
