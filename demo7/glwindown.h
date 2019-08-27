#ifndef GLWINDOWN_H
#define GLWINDOWN_H

#include <QWidget>
#include <QGLWidget>

class QLWindown : public QGLWidget
{
    Q_OBJECT

public:
    QLWindown(QWidget *parent = nullptr);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // QLWINDOWN_H

