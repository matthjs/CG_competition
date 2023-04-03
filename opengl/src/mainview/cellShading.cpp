#include "mainview.ih"

/**
 * @brief MainView::cellShading sets up the cell-shading shader.
 */
void MainView::cellShading()
{
    d_currentShadingMode = ShadingMode::CELL;

    d_shaderProgram.removeAllShaders();

    d_shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                          ":/shaders/vertshader_cell.glsl");
    d_shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                          ":/shaders/fragshader_cell.glsl");
    d_shaderProgram.link();

    // if uniforms have not already been extracted, extract them.
    if (d_shaderUniforms[ShadingMode::CELL].empty())
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
            "u_light_position",
            "u_light_color",
            "u_unlit_color",
            "u_spec_color",
            "u_view",
            "u_diffuseTreshold",
            "u_unlitOutlineThickness",
            "u_litOutlineThickness",
            "u_outlineColor"
        };

        for (auto const &uniformName : uniformNames)
            d_shaderUniforms[ShadingMode::CELL][uniformName]
                = std::unique_ptr<GLint>{ new GLint(d_shaderProgram.uniformLocation(uniformName)) };
    }
}
