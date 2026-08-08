#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aUV;
layout(location = 2) in vec4 aColor;

out vec4 vColor;
out vec2 vUV

uniform mat4 uViewProjection;

uniform sampler2D uDiffuseMap;
uniform sampler2D uNormalMap;
uniform bool uHasNormalMap;

void main() {
    gl_Position = vec4(aPos * uViewProjection;
    vColor = aColor;
    vUV = aUV:
}
