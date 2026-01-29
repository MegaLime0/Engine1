#include <engine/shader.hpp>
#include <engine/loader.hpp>
#include <glad/glad.h>
#include <string>

namespace engine {

Shader::Shader(std::string vPath, std::string fPath) {
    _program = glCreateProgram();

    int vertShader, fragShader;
    vertShader = glCreateShader(GL_VERTEX_SHADER);
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertString = Loader::loadText(vPath);
    const char* vertSource = vertString.c_str();

    std::string fragString = Loader::loadText(fPath);
    const char* fragSource = fragString.c_str();

    glShaderSource(vertShader, 1, &vertSource, 0);
    glShaderSource(fragShader, 1, &fragSource, 0);

    glCompileShader(vertShader);
    // TODO: check errors for vertex shader compilation
    // TODO: compile fragment shader
}


}
