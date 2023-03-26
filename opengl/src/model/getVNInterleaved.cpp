#include "model.ih"

/**
 * @brief Model::getVNInterleaved Retrieves the coordinates and normals of a
 * mesh as separate float values so that all data can be handled by a single
 * buffer. The values are ordered in such a way that they can be used in
 * glDrawArrays. Each vertex consists of 6 float values (3 coordinate, 3
 * normal).
 * @return A list of float values containing the coordinates and normals.
 */
QVector<float> Model::getVNInterleaved()
{
    QVector<float> buffer;

    for (int i = 0; i != vertices.size(); ++i)
    {
        QVector3D vertex = vertices.at(i);
        QVector3D normal = normals.at(i);
        buffer.append(vertex.x());
        buffer.append(vertex.y());
        buffer.append(vertex.z());
        buffer.append(normal.x());
        buffer.append(normal.y());
        buffer.append(normal.z());
    }

    return buffer;
}

/**
 * @brief Model::getVNTInterleaved Retrieves the coordinates, normals and
 * texture coordinates of a mesh as separate float values  so that all data can
 * be handled by a single buffer. The values are ordered in such a way that they
 * can be used in glDrawArrays. Each vertex consists of 8 float values (3
 * coordinate, 3 normal, 2 texture coordinate).
 * @return A list of float values containing the coordinates and normals.
 */
QVector<float> Model::getVNTInterleaved() {
  QVector<float> buffer;

  for (int i = 0; i != vertices.size(); ++i) {
    QVector3D vertex = vertices.at(i);
    QVector3D normal = normals.at(i);
    QVector2D uv = textureCoords.at(i);
    buffer.append(vertex.x());
    buffer.append(vertex.y());
    buffer.append(vertex.z());
    buffer.append(normal.x());
    buffer.append(normal.y());
    buffer.append(normal.z());
    buffer.append(uv.x());
    buffer.append(uv.y());
  }

  return buffer;
}