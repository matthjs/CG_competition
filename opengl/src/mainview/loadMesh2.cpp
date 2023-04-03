#include "mainview.ih"

void MainView::loadMesh(QString const &filename, QVector<QString> const &textureNames)
{
    std::unique_ptr<AbstractModel> model_ptr{ new Model{ filename } };

    glGenVertexArrays(1, &model_ptr->VAO());
    glGenBuffers(1, &model_ptr->VBO());

    for (auto const &textureName : textureNames)
    {
        glGenTextures(1, &model_ptr->enableTextureID());
        model_ptr->addTexture(textureName);
    }

    qDebug() << "in loadMesh size: " << model_ptr->getVertices().size() << '\n';

    d_models.push_back(std::move(model_ptr));
}
