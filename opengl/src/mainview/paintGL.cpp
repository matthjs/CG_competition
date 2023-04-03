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
        // set value of relevant uniform variables (send matrix info to GPU)
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

        for (size_t idx = 0, end = model->numTextures(); idx != end; ++idx)
        {
            glActiveTexture(GL_TEXTURE0 + idx); // activate the texture unit first before binding texture
            glBindTexture(GL_TEXTURE_2D, model->textureID(idx));
        }

        glDrawArrays(GL_TRIANGLES, 0, model->getVertices().size());
    }

    // Generally good practice to unbind the buffers to prevent anything after
    // this from accidentally modifying it.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    d_shaderProgram.release();
}
