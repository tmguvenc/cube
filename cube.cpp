#include "cube.h"
#include <cstring>

Cube::Cube(const float xOffset, const float yOffset, const float zOffset)
    : xOffset(xOffset)
    , yOffset(yOffset)
    , zOffset(zOffset)
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

    std::memcpy(this->vertices, vertices, sizeof(vertices));

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

    std::memcpy(this->colors, colors, sizeof(colors));
}

void Cube::render() {

}

const GLfloat* Cube::getVertices() const {
    return vertices;
}

const GLfloat* Cube::getColors() const {
    return colors;
}

