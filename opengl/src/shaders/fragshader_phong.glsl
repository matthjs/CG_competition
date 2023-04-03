#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the inputs to the fragment shader
// These must have the same type and name!
in vec3 vertNormal;
in vec3 position;
in vec2 textureCoords;

// Specify the Uniforms of the fragment shaders
// uniform vec3 lightPosition; // for example
// material properties
uniform vec3 material_color = vec3(1.0F, 1.0F, 1.0F);
uniform float ka = 0.4;    // ambient coefficient
uniform float kd = 0.4;    // diffuse coefficient
uniform float ks = 0.4;    // specular coefficient
uniform float p = 8;       // specular exponent

// light properties
uniform vec3 light_position = vec3(100.0F, 50.0F, 0.0F);
uniform vec3 light_color = vec3(1.0F, 1.0F, 1.0F);

// view
uniform vec3 view = vec3(0.0F, 0.0F, 0.0F);

// texture related
uniform sampler2D samplerUniform[13];

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;

void main() {
  // evaluate phong illumination model
  vec3 textureColor = texture(samplerUniform[0], textureCoords).xyz;

  vec3 ambient = textureColor * ka;

  vec3 light_dir = normalize(light_position - position);

  vec3 diffuse = max(0.0F, dot(light_dir, vertNormal)) * textureColor * light_color * kd;

  vec3 idealReflection = normalize(reflect(-light_dir, vertNormal));    // ideal reflection of light (R)
  vec3 viewDir = normalize(view - position);

  vec3 specular = max(0.0F, pow(dot(idealReflection, viewDir), p)) * light_color * ks;

  fColor = vec4(ambient + diffuse + specular, 1.0F);
}
