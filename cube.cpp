#include "cube.h"
#include <cstring>

Cube::Cube(const float xOffset, const float yOffset, const float zOffset)
    : m_xOffset(xOffset)
    , m_yOffset(yOffset)
    , m_zOffset(zOffset)
{
    const GLfloat vertices[] = {
        // FRONT
        -0.5f + xOffset, -0.5f + yOffset, 0.5f + zOffset,
         0.5f + xOffset, -0.5f + yOffset, 0.5f + zOffset,
         0.5f + xOffset,  0.5f + yOffset, 0.5f + zOffset,
        -0.5f + xOffset,  0.5f + yOffset, 0.5f + zOffset,

        // BACK
        -0.5f + xOffset, -0.5f + yOffset, -0.5f + zOffset,
        -0.5f + xOffset,  0.5f + yOffset, -0.5f + zOffset,
         0.5f + xOffset,  0.5f + yOffset, -0.5f + zOffset,
         0.5f + xOffset, -0.5f + yOffset, -0.5f + zOffset,

        // LEFT
        -0.5f + xOffset, -0.5f + yOffset,  0.5f + zOffset,
        -0.5f + xOffset,  0.5f + yOffset,  0.5f + zOffset,
        -0.5f + xOffset,  0.5f + yOffset, -0.5f + zOffset,
        -0.5f + xOffset, -0.5f + yOffset, -0.5f + zOffset,

        // RIGHT
         0.5f + xOffset, -0.5f + yOffset, -0.5f + zOffset,
         0.5f + xOffset,  0.5f + yOffset, -0.5f + zOffset,
         0.5f + xOffset,  0.5f + yOffset,  0.5f + zOffset,
         0.5f + xOffset, -0.5f + yOffset,  0.5f + zOffset,

        // TOP
        -0.5f + xOffset, 0.5f + yOffset,  0.5f + zOffset,
         0.5f + xOffset, 0.5f + yOffset,  0.5f + zOffset,
         0.5f + xOffset, 0.5f + yOffset, -0.5f + zOffset,
        -0.5f + xOffset, 0.5f + yOffset, -0.5f + zOffset,

        // BOTTOM
        -0.5f + xOffset, -0.5f + yOffset,  0.5f + zOffset,
        -0.5f + xOffset, -0.5f + yOffset, -0.5f + zOffset,
         0.5f + xOffset, -0.5f + yOffset, -0.5f + zOffset,
         0.5f + xOffset, -0.5f + yOffset,  0.5f + zOffset
    };

    std::memcpy(m_vertices, vertices, sizeof(vertices));

    const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
    };

    std::memcpy(m_colors, colors, sizeof(colors));
}

void Cube::render() {

}

const GLfloat* Cube::getVertices() const {
    return m_vertices;
}

const GLfloat* Cube::getColors() const {
    return m_colors;
}

float Cube::getXOffset() const { return m_xOffset; }
float Cube::getYOffset() const { return m_yOffset; }
float Cube::getZOffset() const { return m_zOffset; }
