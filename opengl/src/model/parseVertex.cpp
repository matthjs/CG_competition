#include "model.ih"

/**
 * @brief Model::parseVertex Parses the coordinates of a vertex from the
 * .obj file.
 * @param tokens Tokens on the line in question.
 */
void Model::parseVertex(QStringList tokens)
{
    float x = tokens[1].toFloat();
    float y = tokens[2].toFloat();
    float z = tokens[3].toFloat();
    vertices_indexed.append(QVector3D(x, y, z));
}
