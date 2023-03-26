#include "model.ih"

/**
 * @brief Model::parseTexture Parses a texture coordinate from the .obj file.
 * @param tokens Tokens on the line in question.
 */
void Model::parseTexture(QStringList tokens)
{
    hTexs = true;
    float u = tokens[1].toFloat();
    float v = tokens[2].toFloat();
    tex.append(QVector2D(u, v));
}