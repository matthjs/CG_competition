#include "mainview.ih"

/**
 * @brief MainView::gouraudShading sets up the gouraud shader.
 */
void MainView::gouraudShading()
{
    d_currentShadingMode = ShadingMode::GOURAUD;
    
    d_shaderProgram.removeAllShaders();

    d_shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                          ":/shaders/vertshader_gouraud.glsl");
    d_shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                          ":/shaders/fragshader_gouraud.glsl");
    d_shaderProgram.link();

    // if uniforms have not already been extracted, extract them.
    if (d_shaderUniforms[ShadingMode::GOURAUD].empty())
    {
        // extract locations of uniforms
        std::vector<QString> const uniformNames
        {
            "projectionTransform",
            "modelViewTransform",
            "normalTransform",
            "material_color",
            "ka",
            "kd",
            "ks",
            "p",
            "light_position",
            "light_color",
            "view",
        };

        for (auto const &uniformName : uniformNames)
            d_shaderUniforms[ShadingMode::GOURAUD][uniformName]
                = std::unique_ptr<GLint>{ new GLint(d_shaderProgram.uniformLocation(uniformName)) };
    }
}
