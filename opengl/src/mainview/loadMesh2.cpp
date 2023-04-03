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
/**
 * @brief MainView::loadMesh loads a mesh from <filename> with texture file
 * from <textureFIleName>.
 * A smart pointer to the resulting model object is then added
 * to the models container.
 * @param filename
 * NOTE: also generated VAO and VBO for mesh.
 */
void MainView::loadMesh(QString const &filename, QString const &textureFileName)
{
    std::unique_ptr<AbstractModel> model_ptr{ new Model{ filename } };

    glGenVertexArrays(1, &model_ptr->VAO());
    glGenBuffers(1, &model_ptr->VBO());
    glGenTextures(1, &model_ptr->textureID());

    model_ptr->setTexture(QImage{ textureFileName });

    qDebug() << "in loadMesh size: " << model_ptr->getVertices().size() << '\n';

    d_models.push_back(std::move(model_ptr));
}
