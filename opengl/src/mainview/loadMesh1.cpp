#include "mainview.ih"

/**
 * @brief MainView::loadMesh loads a mesh from <filename>.
 * A smart pointer to the resulting model object is then added
 * to the models container.
 * @param filename
 * NOTE: also generated VAO and VBO for mesh.
 * NOTE: DO NOT RUN THIS, THE PROGRAM CURRENTLY DOES NOT SUPPORT
 * MESHES WITHOUT TEXTURES.
 */
void MainView::loadMesh(QString const &filename)
{
    std::unique_ptr<AbstractModel> model_ptr{ new Model{ filename } };

    glGenVertexArrays(1, &model_ptr->VAO());
    glGenBuffers(1, &model_ptr->VBO());

    qDebug() << "in loadMesh size: " << model_ptr->getVertices().size() << '\n';

    d_models.push_back(std::move(model_ptr));
}
