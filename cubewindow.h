#ifndef CUBEWINDOW_H
#define CUBEWINDOW_H

#include "openglwindow.h"
#include <QOpenGLShaderProgram>
#include <QScreen>
#include "cube.h"
#include <vector>

class CubeWindow : public OpenGLWindow
{
public:
    using OpenGLWindow::OpenGLWindow;

    void initialize() override;
    void render() override;

public:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void addCube();

private:
    GLint m_posAttr = 0;
    GLint m_colorAttr = 0;
    GLint m_matrixUniform = 0;

    QOpenGLShaderProgram *m_program = nullptr;
    int m_frame = 0;

    std::vector<Cube> cubes;
};

#endif // CUBEWINDOW_H
