#include <engine/shader.hpp>
#include <engine/loader.hpp>
#include <glad/glad.h>
#include <stdexcept>
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

    int status;
    char log[256];

    glCompileShader(vertShader);
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &status);

    if (status == 0) {
        glGetShaderInfoLog(vertShader, sizeof(log), 0, log);
        throw std::runtime_error("Couldn't compile vertex shader: " + std::string(log));
    }
    status = 0;

    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &status);

    if (status == 0) {
        glGetShaderInfoLog(fragShader, sizeof(log), 0, log);
        throw std::runtime_error("Couldn't compile fragment shader: " + std::string(log));
    }
    status = 0;

    glAttachShader(_program, vertShader);
    glAttachShader(_program, fragShader);

    glLinkProgram(_program);
    glGetProgramiv(_program, GL_LINK_STATUS, &status);

    if (status == 0) {
        glGetProgramInfoLog(_program, sizeof(log), 0, log);
        throw std::runtime_error("Couldn't link program: " + std::string(log));
    }

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    _valid = true;
}

Shader::~Shader() {
    deleteProgram();
}

void Shader::use() {
    glUseProgram(_program);
}

void Shader::deleteProgram() {
    glDeleteProgram(_program);
    _valid = false;
}

bool Shader::isValid() {
    return _valid;
}

}   // namespace engine
