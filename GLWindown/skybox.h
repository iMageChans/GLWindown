#ifndef SKYBOX_H
#define SKYBOX_H

#include <QObject>
#include <ggl.h>

class skybox
{
public:
    void initializeImage(const char* imageDir, int &index);
    void Init(const char* imageDir[]);
    void DarwCommand();
    void Darw();

    GLuint mTexture[6];
    GLuint mFastDrawCall;
};

#endif // SKYBOX_H
