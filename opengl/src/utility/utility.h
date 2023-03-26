#ifndef UTILITY_H
#define UTILITY_H

#include <QKeyEvent>
#include <QMouseEvent>
#include <QOpenGLDebugLogger>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QTimer>
#include <QVector3D>
#include <unordered_map>
#include <string>
#include <vector>

QVector<quint8> imageToBytes(QImage const &image);

#endif