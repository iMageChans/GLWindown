#ifndef GLWINDOWN_H
#define GLWINDOWN_H

#include <QWidget>
#include <QGLWidget>

class GLWindown : public QGLWidget
{
    Q_OBJECT

public:
    GLWindown(QWidget *parent = nullptr);
    GLuint texture;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void loadGLTextures();
};

#endif // GLWINDOWN_H
