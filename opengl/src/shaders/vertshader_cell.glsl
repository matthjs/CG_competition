#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout(location = 0) in vec3 vertCoordinates_in;
layout(location = 1) in vec3 vertNormal_in;
layout(location = 2) in vec2 textureCoordinates0_in;
layout(location = 3) in vec2 textureCoordinates1_in;
layout(location = 4) in vec2 textureCoordinates2_in;
layout(location = 5) in vec2 textureCoordinates3_in;
layout(location = 6) in vec2 textureCoordinates4_in;
layout(location = 7) in vec2 textureCoordinates5_in;
layout(location = 8) in vec2 textureCoordinates6_in;
layout(location = 9) in vec2 textureCoordinates7_in;
layout(location = 10) in vec2 textureCoordinates8_in;
layout(location = 11) in vec2 textureCoordinates9_in;
layout(location = 12) in vec2 textureCoordinates10_in;
layout(location = 13) in vec2 textureCoordinates11_in;
layout(location = 14) in vec2 textureCoordinates12_in;

// Specify the Uniforms of the vertex shader
uniform mat4 projectionTransform;
uniform mat4 modelViewTransform;
uniform mat3 normalTransform;

// Specify the output of the vertex stage
out vec3 vertNormal;
out vec3 position;
out vec2 textureCoords0;
out vec2 textureCoords1;
out vec2 textureCoords2;
out vec2 textureCoords3;
out vec2 textureCoords4;
out vec2 textureCoords5;
out vec2 textureCoords6;
out vec2 textureCoords7;
out vec2 textureCoords8;
out vec2 textureCoords9;
out vec2 textureCoords10;
out vec2 textureCoords11;
out vec2 textureCoords12;

void main() {
  // gl_Position is the output (a vec4) of the vertex shader
  gl_Position =
      projectionTransform * modelViewTransform * vec4(vertCoordinates_in, 1.0F);

  position = vec3(modelViewTransform * vec4(vertCoordinates_in, 1.0F));
  vertNormal = normalize(normalTransform * vertNormal_in);
  textureCoords0 = textureCoordinates0_in;
textureCoords1 = textureCoordinates1_in;
textureCoords2 = textureCoordinates2_in;
textureCoords3 = textureCoordinates3_in;
 textureCoords4 = textureCoordinates4_in;
textureCoords5 = textureCoordinates5_in;
 textureCoords6 = textureCoordinates6_in;
 textureCoords7 = textureCoordinates7_in;
  textureCoords8 = textureCoordinates8_in;
 textureCoords9 = textureCoordinates9_in;
 textureCoords10 = textureCoordinates10_in;
 textureCoords11 = textureCoordinates11_in;
 textureCoords12 = textureCoordinates12_in;


}
