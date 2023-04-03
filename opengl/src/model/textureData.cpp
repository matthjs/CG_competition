#include "model.ih"
#include "../utility/utility.h"

// This implementation would eventually replace the below one.
QVector<quint8> Model::textureData(size_t idx) const
{
    return imageToBytes(d_textures[idx]);
}

/**
 * @brief Model::textureData gets d_texture as a 
 * QVector<quint8> object.
 * NOTE: run data() on QVector to get raw data.
 */
QVector<quint8> Model::textureData() const
{
    return imageToBytes(d_texture);
}
