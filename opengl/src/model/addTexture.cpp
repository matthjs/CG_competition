#include "model.ih"

void Model::addTexture(QString const &textureName)
{
    d_textures.push_back(QImage{ textureName });
}
