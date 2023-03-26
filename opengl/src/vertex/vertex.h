#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>
#include <QVector2D>
#include <initializer_list>

/**
 * @brief Represents a single vertex with coordinates and an rgb color.
 */
struct Vertex
{
    QVector3D d_coords;
    QVector3D d_normal;
    QVector2D d_textureCoords;

    Vertex() = default;
    Vertex(QVector3D coords, QVector3D normal);    // 1
    Vertex(std::initializer_list<float> iniValues);    // 2
    QVector2D const &getTextureCoords() const;
};

#endif  // VERTEX_H