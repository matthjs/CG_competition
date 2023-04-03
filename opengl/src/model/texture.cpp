#include "model.ih"

/**
 * @brief Model::texture is a getter for d_texture.
 */
QImage const &Model::texture(size_t idx) const
{
    return d_textures[idx];
}
