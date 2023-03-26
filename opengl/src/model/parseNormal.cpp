#include "model.ih"

/**
 * @brief Model::parseNormal Parses the normals of a vertex from the
 * .obj file.
 * @param tokens Tokens on the line in question.
 */
void Model::parseNormal(QStringList tokens)
{
    hNorms = true;
    float x = tokens[1].toFloat();
    float y = tokens[2].toFloat();
    float z = tokens[3].toFloat();
    norm.append(QVector3D(x, y, z));
}