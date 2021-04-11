#ifndef CUBE_H
#define CUBE_H

#include <GL/gl.h>

class Cube
{
public:
    Cube(const float xOffset, const float yOffset, const float zOffset);

    void render();

    const GLfloat* getVertices() const;
    const GLfloat* getColors() const;

private:
    const float xOffset;
    const float yOffset;
    const float zOffset;

    GLfloat vertices[72];
    GLfloat colors[72];
};

#endif // CUBE_H
