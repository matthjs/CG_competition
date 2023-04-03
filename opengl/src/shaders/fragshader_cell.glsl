/*
Based on: https://en.wikibooks.org/wiki/GLSL_Programming/Unity/Toon_Shading
cell shading is a form of non-photorealistic rendering. The lighting
calculations are per-pixel just as phong shading. Lighting calculations
are adjusted to recreate the look of traditional 2D animation cells or more
generally to give a more cartoon-ish look.

*/
#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the inputs to the fragment shader
// These must have the same type and name!
in vec3 vertNormal;
in vec3 position;
in vec2 textureCoords0;
in vec2 textureCoords1;
in vec2 textureCoords2;
in vec2 textureCoords3;
in vec2 textureCoords4;
in vec2 textureCoords5;
in vec2 textureCoords6;
in vec2 textureCoords7;
in vec2 textureCoords8;
in vec2 textureCoords9;
in vec2 textureCoords10;
in vec2 textureCoords11;
in vec2 textureCoords12;

// Specify the Uniforms of the fragment shaders
// uniform vec3 lightPosition; // for example
// material properties
uniform vec3 u_material_color = vec3(1.0F, 1.0F, 1.0F);    // texture data is actually used
uniform float ka = 0.4;    // ambient coefficient
uniform float kd = 0.4;    // diffuse coefficient
uniform float ks = 0.4;    // specular coefficient
uniform float p = 8;       // specular exponent

// light properties
uniform vec4 u_light_position = vec4(100.0F, 50.0F, 0.0F, 1.0F);
uniform vec4 u_light_color = vec4(1.0F, 1.0F, 1.0F, 1.0F);
uniform vec4 u_unlit_color = vec4(0.0F, 0.0F, 0.0F, 1.0F);
uniform vec4 u_spec_color = vec4(1.0F, 1.0F, 1.0F, 1.0F);

// view
uniform vec3 u_view = vec3(0.0F, 0.0F, 0.0F);

// texture related
uniform sampler2D u_samplerUniform[13];

// more shading properties
uniform float u_diffuseTreshold = 0.0F;
uniform float u_unlitOutlineThickness = 0.1;
uniform float u_litOutlineThickness = 0.4;
uniform vec4 u_outlineColor = vec4(0.0F, 0.0F, 0.0F, 0.0F);

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;

void main()
{
    vec3 light_position = vec3(u_light_position);
    vec3 normalDir = normalize(vertNormal);    // maybe vertex normal is already normalized
    vec3 lightDir = normalize(light_position - position);
    vec3 viewDir = normalize(u_view - position);  // note that right now view is fixed
    float attenuation;

    // note that light position is also fixed right now
    if (u_light_position.w == 0.0)    // directional light?
    {
        attenuation = 1.0;    // no attenuation
        lightDir= normalize(light_position);
    }
    else    // point or spot light
    {
        float dist = length(light_position - position);
        attenuation = 1.0 / dist;    // linear attenuation
    }

    vec3 textureColor;
    float weight = 1;

    textureColor += weight * texture(u_samplerUniform[0], textureCoords0).xyz;
    /*
    textureColor += weight * texture(u_samplerUniform[1], textureCoords1).xyz;
    textureColor += weight * texture(u_samplerUniform[2], textureCoords2).xyz;
    textureColor += weight * texture(u_samplerUniform[3], textureCoords3).xyz;
    textureColor += weight * texture(u_samplerUniform[4], textureCoords4).xyz;
    textureColor += weight * texture(u_samplerUniform[5], textureCoords5).xyz;
    textureColor += weight * texture(u_samplerUniform[6], textureCoords6).xyz;
    textureColor += weight * texture(u_samplerUniform[7], textureCoords7).xyz;
    textureColor += weight * texture(u_samplerUniform[8], textureCoords8).xyz;
    textureColor += weight * texture(u_samplerUniform[9], textureCoords9).xyz;
    textureColor += weight * texture(u_samplerUniform[10], textureCoords10).xyz;
    textureColor += weight * texture(u_samplerUniform[11], textureCoords11).xyz;
    textureColor += weight * texture(u_samplerUniform[12], textureCoords12).xyz;
    */

    // default: add ambient component
    vec3 fragmentColor = vec3(textureColor * ka);

    // stylized diffuse illumination
    if (attenuation * max(0.0, dot(normalDir, lightDir)) >= u_diffuseTreshold)
    {
        fragmentColor += vec3(u_light_color) * vec3(textureColor) * kd;
    }

    // higher priority: outline
    if (dot(viewDir, normalDir)
          < mix(u_unlitOutlineThickness, u_litOutlineThickness,
          max(0.0, dot(normalDir, lightDir))))
    {
        fragmentColor = vec3(u_light_color) * vec3(u_outlineColor);
    }

    // stylized specular highlights
    if (dot(normalDir, lightDir) > 0.0
        && attenuation * pow(max(0.0, dot(
          normalize(reflect(-lightDir, normalDir)),
          viewDir
        )), p) > 0.5)    // more than half highlight intensity?
    {
        fragmentColor = u_spec_color.a *
                        vec3(u_light_color) * vec3(u_spec_color)
                        + (1.0 - u_spec_color.a) * fragmentColor * ks;
    }

    fColor = vec4(fragmentColor, 1.0F);
}
