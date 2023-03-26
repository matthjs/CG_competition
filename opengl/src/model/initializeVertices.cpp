#include "model.ih"

/**
 * @brief Model::initializeVertices generates a vector of vertices
 * based on the QVector<QVector3D> d_coords data member.
 */
void Model::initializeVertices()
{
    d_complete_vertices.clear();
    d_complete_vertices.resize(vertices.size());

    for (int idx = 0; idx != vertices.size(); ++idx)
    {
        d_complete_vertices[idx].d_coords = vertices[idx];
        d_complete_vertices[idx].d_normal = normals[idx];
        d_complete_vertices[idx].d_textureCoords = textureCoords[idx];
    }
}