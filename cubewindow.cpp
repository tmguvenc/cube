#include "cubewindow.h"
#include <QMouseEvent>

static const char *vertexShaderSource =
    "attribute highp vec4 posAttr;\n"
    "attribute lowp vec4 colorAttr;\n"
    "varying lowp vec4 color;\n"
    "uniform highp mat4 matrix;\n"
    "void main() {\n"
    "   color = colorAttr;\n"
    "   gl_Position = matrix * posAttr;\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying lowp vec4 color;\n"
    "void main() {\n"
    "   gl_FragColor = color;\n"
    "}\n";

static constexpr auto scaler  = 1.0 / 255.0;

void CubeWindow::initialize()
{
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_colorAttr = m_program->attributeLocation("colorAttr");
    Q_ASSERT(m_colorAttr != -1);
    m_matrixUniform = m_program->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);
}

int x_coord = 0;
bool pressed = false;

void CubeWindow::mouseMoveEvent(QMouseEvent *event) {
    if(pressed) {
        x_coord = event->x();
    }
}

void CubeWindow::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    pressed = true;
}

void CubeWindow::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    pressed = false;
}

void CubeWindow::render()
{
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClearColor(0x7F * scaler, 0x7C * scaler, 0xCC * scaler, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(-0.3, 0.2, -2);
    matrix.rotate(25.0f * x_coord / screen()->refreshRate(), 0, 1, 0);

    m_program->setUniformValue(m_matrixUniform, matrix);

    static const GLfloat vertices[] = {
        -0.5f, -0.5f, 0.5f,
         0.5f, -0.5f, 0.5f,
         0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,
         0.5f, 0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, 0.5f, -0.5f,
         0.5f, 0.5f, 0.5f,
         0.5f, -0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f,
         0.5f, 0.5f, 0.5f,
         0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,
        -0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, 0.5f
    };

    static const GLfloat colors[] = {
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
        0.0f, 0.0f, 1.0f
    };

    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(m_colorAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colorAttr);

    glDrawArrays(GL_QUADS, 0, 24);

    glDisableVertexAttribArray(m_colorAttr);
    glDisableVertexAttribArray(m_posAttr);

    m_program->release();

    ++m_frame;
}
