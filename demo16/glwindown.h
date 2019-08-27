#ifndef GLWINDOWN_H
#define GLWINDOWN_H

#include <QMainWindow>

class GLWindown : public QMainWindow
{
    Q_OBJECT

public:
    GLWindown(QWidget *parent = 0);
    ~GLWindown();
};

#endif // GLWINDOWN_H
