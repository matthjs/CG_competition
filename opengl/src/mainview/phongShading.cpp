#include "mainview.ih"

/**
 * @brief MainView::phongShading sets up phong shader.
 */
void MainView::phongShading()
{
    d_currentShadingMode = ShadingMode::PHONG;

    d_shaderProgram.removeAllShaders();

    d_shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                          ":/shaders/vertshader_phong.glsl");
    d_shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                          ":/shaders/fragshader_phong.glsl");
    d_shaderProgram.link();

    // if uniforms have not already been extracted, extract them.
    if (d_shaderUniforms[ShadingMode::PHONG].empty())
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
            "samplerUniform"
        };

        for (auto const &uniformName : uniformNames)
            d_shaderUniforms[ShadingMode::PHONG][uniformName]
                = std::unique_ptr<GLint>{ new GLint(d_shaderProgram.uniformLocation(uniformName)) };
    }
}
