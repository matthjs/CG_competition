#include "model.ih"

/**
 * Adds Gluint to textureID internal vector
 * Returns Gluint which can be addressed
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
