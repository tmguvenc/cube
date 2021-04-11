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
    float getXOffset() const;
    float getYOffset() const;
    float getZOffset() const;

private:
    const float m_xOffset;
    const float m_yOffset;
    const float m_zOffset;

    GLfloat m_vertices[72];
    GLfloat m_colors[72];
};

#endif // CUBE_H
