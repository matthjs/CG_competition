#include "mainview.ih"

/**
 * @brief MainView::destroyModelBuffers destroys modelbuffers (run in destructor)
 */
void MainView::destroyModelBuffers()
{
    for (auto &model : d_models)
    {
        glDeleteBuffers(1, &model->VBO());
        glDeleteVertexArrays(1, &model->VAO());
        glDeleteTextures(1, &model->textureID());
    }
}