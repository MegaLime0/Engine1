#include <engine/render/shader.hpp>
#include <engine/loader.hpp>
#include <stdexcept>
#include <string>

namespace Engine {
namespace Render {

Shader::Shader(const std::string& vPath, const std::string& fPath) {
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

}

Shader::~Shader() {
    deleteProgram();
}

void Shader::use() {
    glUseProgram(_program);
}

void Shader::deleteProgram() {
    glDeleteProgram(_program);
}

// TODO: implement shader cacheing
void Shader::cache(std::string path, std::string name) {

}

GLint Shader::getUniformLocation(std::string uniform) {
    // find uniform location, if not cached, cache it
    std::unordered_map<std::string, GLint>::iterator target = uniformCache.find(uniform);
    if (target == uniformCache.end()) {
        GLint location = glGetUniformLocation(_program, uniform.c_str());
        uniformCache.emplace(uniform, location);
        return location;
    } else {
        return target->second;
    }
}

// TODO: complete uniform sets
void Shader::setUniform1(std::string uniform, float v) {
    GLint location = getUniformLocation(uniform);
    glUniform1f(location, v);
}

void Shader::setUniform2(std::string uniform, glm::vec2 v) {
    GLint location = getUniformLocation(uniform);
    glUniform2f(location, v.x, v.y);

}

void Shader::setUniform3(std::string uniform, glm::vec3 v) {
    GLint location = getUniformLocation(uniform);
    glUniform3f(location, v.x, v.y, v.z);
}

void Shader::setUniform4(std::string uniform, glm::vec4 v) {
    GLint location = getUniformLocation(uniform);
    glUniform4f(location, v.x, v.y, v.z, v.w);
}

} // namespace render
} // namespace engine
