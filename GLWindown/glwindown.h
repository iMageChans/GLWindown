#ifndef GLWINDOWN_H
#define GLWINDOWN_H

#include <QWidget>
#include <QGLWidget>
#include "skybox.h"

class GLWindown : public QGLWidget
{
    Q_OBJECT

public:
    GLWindown(QWidget *parent = nullptr);
//    void initializeImage(const char* imageDir, int &index);
//    GLuint mTexture[6];
    GLuint texture;
    skybox box;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void loadGLTextures();
};

#endif // GLWINDOWN_H
