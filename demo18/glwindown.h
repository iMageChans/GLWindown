#ifndef GLWINDOWN_H
#define GLWINDOWN_H

#include <QWidget>
#include <QGLWidget>

class GLWindown : public QGLWidget
{
    Q_OBJECT

public:
    GLWindown(QWidget *parent = 0);
    unsigned char* LoadFile(const char* path, int &filesize);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // GLWINDOWN_H
