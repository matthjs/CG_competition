#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout(location = 0) in vec3 vertCoordinates_in;
layout(location = 1) in vec3 vertNormal_in;

// Specify the Uniforms of the vertex shader
uniform mat4 projectionTransform;
uniform mat4 modelViewTransform;
uniform mat3 normalTransform;

// Specify the output of the vertex stage
out vec3 vertNormal;
out vec3 vertColor;

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

void main() {
  // gl_Position is the output (a vec4) of the vertex shader
  gl_Position =
      projectionTransform * modelViewTransform * vec4(vertCoordinates_in, 1.0F);
    
  vec3 position = vec3(modelViewTransform * vec4(vertCoordinates_in, 1.0F));

  vertNormal = normalize(normalTransform * vertNormal_in);

  // evaluate phong illumination model
  vec3 ambient = material_color * ka;

  vec3 light_dir = normalize(light_position - position);

  vec3 diffuse = max(0.0F, dot(light_dir, vertNormal)) * material_color * light_color * kd;

  vec3 idealReflection = normalize(reflect(-light_dir, vertNormal));    // ideal reflection of light (R)
  vec3 viewDir = normalize(view - position);

  vec3 specular = max(0.0F, pow(dot(idealReflection, viewDir), p)) * light_color * ks;

  vertColor = ambient + diffuse + specular;
}
