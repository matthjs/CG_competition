#include "model.ih"

/**
 *
 */
GLuint &Model::enableTextureID()
{
    d_textureIDs.push_back(GLuint{});
    return d_textureIDs.back();
}

GLuint &Model::textureID(size_t idx)
{
    return d_textureIDs[idx];
}

GLuint &Model::textureID()
{
    return d_textureID;
}
