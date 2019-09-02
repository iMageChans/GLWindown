#ifndef UTILS_H
#define UTILS_H

#include "ggl.h"
#include <QImage>

void setQuadsFront(GLuint texture);
void setQuadsLeft(GLuint texture);
void setQuadsRight(GLuint texture);
void setQuadsTop(GLuint texture);
void setQuadsBottom(GLuint texture);
void setQuadsBack(GLuint texture);
const QImage DecodeBMP(const char* bmpPath);
GLuint CreateTexture2D(QImage pixelData, GLenum type);
GLuint CreateTexture2DFromBMP(const char* bmpPath);
GLuint CreateDisplayList(std::function<void()>foo);

#endif // UTILS_H
