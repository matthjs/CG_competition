#include "mainview.ih"

void MainView::uploadTextureData(AbstractModel const &model)
{
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA8,
        model.texture().width(),
        model.texture().height(),
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        model.textureData().data()
    );
}
