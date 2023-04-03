#include "model.ih"

void Model::addTexture(QString const &textureName)
{
    d_textures.push_back(QImage{ textureName });
}

/**
 * @brief Model::setTexture sets texture image.
 * @param image
 */
void Model::setTexture(QImage const &image)
{
    d_texture = image;
}
