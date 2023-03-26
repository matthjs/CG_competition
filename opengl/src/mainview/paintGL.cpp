#include "mainview.ih"

/**
 * @brief MainView::paintGL Actual function used for drawing to the screen.
 * Loops over all models and renders them.
 */
void MainView::paintGL()
{
    // Clear the screen before rendering
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    d_shaderProgram.bind();

    // upload projection transform
    glUniformMatrix4fv(
        *(d_shaderUniforms[d_currentShadingMode]["projectionTransform"]),
        1,
        GL_FALSE,
        d_projectionTransform.data()
    );

    for (auto &model : d_models)
    {
        // set value of uniform variables (send matrix info to GPU)
        glUniformMatrix4fv
        (
            *(d_shaderUniforms[d_currentShadingMode]["modelViewTransform"]),
            1,
            GL_FALSE,
            model->meshTransform().data()
        );

        glUniformMatrix3fv
        (
            *(d_shaderUniforms[d_currentShadingMode]["normalTransform"]),
            1,
            GL_FALSE,
            model->normalTransform().data()
        );

        glBindVertexArray(model->VAO());

        glBindTexture(GL_TEXTURE_2D, model->textureID());

        /*
        // texture stuff
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, model->textureID());
        // set how openGL will interpret texture
        setTextureInterpretation();
        // upload texture data
        uploadTextureData(*model);
        glGenerateMipmap(GL_TEXTURE_2D);
        */

        /*
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
        */

        glDrawArrays(GL_TRIANGLES, 0, model->getVertices().size());
    }

    // Generally good practice to unbind the buffers to prevent anything after
    // this from accidentally modifying it.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    d_shaderProgram.release();
}
