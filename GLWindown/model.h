#ifndef MODEL_H
#define MODEL_H
#include "ggl.h"
struct VertexData{
    float position[3];
    float normal[3];
    float texcoord[3];
};

class Model
{
public:
    GLuint mTexture;
    VertexData *mVertexes;
    unsigned short *mIndexes;
    int mIndexCount;
    Model();
    void Init(const char* modelPath);
    void Draw();
};

#endif // MODEL_H
