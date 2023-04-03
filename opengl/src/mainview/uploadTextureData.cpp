#include "mainview.ih"
#include "../utility/utility.h"

void MainView::uploadTextureData(QImage const &texture)
{
    //for (size_t idx = 0, end = model.numTextures(); idx != end; ++idx)
   // {
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA8,
            texture.width(),
            texture.height(),
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            imageToBytes(texture).data()
        );
        glGenerateMipmap(GL_TEXTURE_2D);
    //}
}
