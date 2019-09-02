#ifndef SKYBOX_H
#define SKYBOX_H

#include <QObject>
#include <ggl.h>
#include <QOpenGLTexture>

class skybox : public QObject
{
    Q_OBJECT
public:
    explicit skybox(QObject *parent = nullptr);
    void initializeImage(const char* imageDir, int &index, GLuint texture);
    void Init(const char* imageDir[], GLuint texture);
    void DarwCommand();
    void Darw();

    GLuint mTexture[6];
    GLuint mFastDrawCall;

signals:

public slots:
};

#endif // SKYBOX_H
