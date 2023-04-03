#include "mainview.ih"

void MainView::initializeSamplers(size_t numTextures)
{
    QString const uniformName{ "u_samplerUniform" };

    for (size_t idx = 0; idx != numTextures; ++idx)
    {
        QString uName = uniformName + "[" + QString::number(idx) + "]";

        glUniform1i(d_shaderProgram.uniformLocation(uName), idx);
    }
}
// let OpenGL know which texture unit each shader sampler belongs to
// convention: Texture0 -> 0 -> sampler2D[0]
// note that the uniforms are not saved
// note that it assumes samplers are named u_samplerUniform
