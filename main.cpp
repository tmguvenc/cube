#include<stdio.h>
#include "mainwindow.h"
#include <qguiapplication.h>
#include <QSurfaceFormat>
#include "cubewindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QSurfaceFormat format;
    format.setSamples(16);

    CubeWindow window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();

    window.setAnimating(true);

    return app.exec();
}
