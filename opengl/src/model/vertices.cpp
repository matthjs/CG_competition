#include "model.ih"

/**
 * @brief Model::getVertices returns (a reference to) 
 * vertices as a vector of vertices.
 */
QVector<Vertex> &Model::getVertices()
{
    if (d_complete_vertices.empty())
        initializeVertices();

    return d_complete_vertices;
}