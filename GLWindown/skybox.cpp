#include "skybox.h"
#include <QGLWidget>
#include "utils.h"


void skybox::Init(const char* imageDir[]){
    for(int i = 0; i < 6; i++){
        initializeImage(imageDir[i], i);
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

void skybox::initializeImage(const char* imageDir, int &index){
    mTexture[index] = CreateTexture2DFromBMP(imageDir);
}

void skybox::Darw(){
    glCallList(mFastDrawCall);
}
