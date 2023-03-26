#include "mainview.ih"

/**
 * @brief MainView::normalShading sets up the normal shader.
 */
void MainView::normalShading()
{
    d_currentShadingMode = ShadingMode::NORMAL;

    d_shaderProgram.removeAllShaders();

    d_shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                          ":/shaders/vertshader_normal.glsl");
    d_shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                          ":/shaders/fragshader_normal.glsl");
    d_shaderProgram.link();

    // if uniforms have not already been extracted, extract them.
    if (d_shaderUniforms[ShadingMode::NORMAL].empty())
    {
        // extract locations of uniforms
        std::vector<QString> const uniformNames
        {
            "projectionTransform",
            "modelViewTransform",
            "normalTransform"
        };

        for (auto const &uniformName : uniformNames)
            d_shaderUniforms[ShadingMode::NORMAL][uniformName]
                    = std::unique_ptr<GLint>{ new GLint(d_shaderProgram.uniformLocation(uniformName)) };
    }
}
