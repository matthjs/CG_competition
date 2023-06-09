#include "mainview.ih"

/**
 * @brief MainView::initializeGL Called upon OpenGL initialization
 * Attaches a debugger and calls other init functions.
 */
void MainView::initializeGL()
{
    qDebug() << ":: Initializing OpenGL";
    initializeOpenGLFunctions();

    connect(&d_debugLogger, SIGNAL(messageLogged(QOpenGLDebugMessage)), this,
            SLOT(onMessageLogged(QOpenGLDebugMessage)), Qt::DirectConnection);

    if (d_debugLogger.initialize())
    {
      qDebug() << ":: Logging initialized";
      d_debugLogger.startLogging(QOpenGLDebugLogger::SynchronousLogging);
    }

    QString glVersion{reinterpret_cast<const char *>(glGetString(GL_VERSION))};
    qDebug() << ":: Using OpenGL" << qPrintable(glVersion);

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);
    // Enable backface culling
    glEnable(GL_CULL_FACE);
    // Default is GL_LESS
    glDepthFunc(GL_LEQUAL);

    // Set the color to be used by glClear. This is, effectively, the background
    // color.
    glClearColor(0.37f, 0.42f, 0.45f, 0.0f);

    createShaderProgram();

    
    loadMesh("./models/cat.obj", QVector<QString>
    { 
      "./textures/cat_diff.png"
    });

    // Initialize transformations
    updateProjectionTransform();
    updateModelTransforms();

    // anisotropic filtering
    GLfloat f;
    glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT,&f);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,f);

    d_shaderProgram.bind();
  
    // upload static model information to GPU/shaders
    // note that generating VBO and VAO buffers is done in loadmesh()
    for (auto &model : d_models)
    {
        glBindVertexArray(model->VAO());
        glBindBuffer(GL_ARRAY_BUFFER, model->VBO());

        // texture stuff
        for (size_t idx = 0, end = model->numTextures(); idx != end; ++idx)
        {
            glBindTexture(GL_TEXTURE_2D, model->textureID(idx));
            setTextureInterpretation();
            uploadTextureData(model->texture(idx));
        }

        // This should be in seperate function
        initializeSamplers(model->numTextures());

        // upload vertices to the GL_ARRAY_BUFFER
        glBufferData(GL_ARRAY_BUFFER, model->getVertices().size() * sizeof(Vertex), model->getVertices().data(), GL_STATIC_DRAW);

        // Set vertex coordinates to location 0
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                reinterpret_cast<GLvoid *>(0));
        glEnableVertexAttribArray(0);

        // Set color values to location 1
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                reinterpret_cast<GLvoid *>(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        // set texture coordinates in location 2
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                reinterpret_cast<GLvoid *>(6 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);
    }

    d_shaderProgram.release();
}
