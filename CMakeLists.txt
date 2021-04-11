cmake_minimum_required(VERSION 3.5)

project(sample LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

add_executable(sample
main.cpp
mainwindow.cpp
mainwindow.h
mainwindow.ui
openglwindow.h
openglwindow.cpp
trianglewindow.cpp
trianglewindow.h
cubewindow.cpp
cubewindow.h
cube.h
cube.cpp
)

target_link_libraries(sample PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(sample PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(sample PRIVATE ${GLUT_LIBRARY})
