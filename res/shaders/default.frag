#version 330 core

in vec4 vColor;
in vec2 vUV;

out vec4 FragColor;

uniform sampler2D diffuseMap;
uniform sampler2D normalMap;

void main() {
    FragColor = texture(diffuseMap, vUV) * vColor;
}
