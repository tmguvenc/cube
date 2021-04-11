#ifndef CUBEWINDOW_H
#define CUBEWINDOW_H

#include "openglwindow.h"
#include <QOpenGLShaderProgram>
#include <QScreen>

class CubeWindow : public OpenGLWindow
{
public:
    using OpenGLWindow::OpenGLWindow;

    void initialize() override;
    void render() override;

public:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    GLint m_posAttr = 0;
    GLint m_colorAttr = 0;
    GLint m_matrixUniform = 0;

    QOpenGLShaderProgram *m_program = nullptr;
    int m_frame = 0;
};

#endif // CUBEWINDOW_H
