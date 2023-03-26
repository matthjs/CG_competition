#include "model.ih"

/**
 * Also generates GLUINT
void Model::addTexture(QString const &textureName)
{
    d_textures.reserve(textureNames.size());
    for (size_t idx = 0, end = textureNames.size(); idx != end; ++idx)
        new(&d_textures[idx]) QImage{ textureNames[idx] };
}
*/

/**
 * @brief Model::setTexture sets texture image.
 * @param image
 */
void Model::setTexture(QImage const &image)
{
    d_texture = image;
}
