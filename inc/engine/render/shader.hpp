#pragma once

#include <engine/base_asset.hpp>
#include <string>
#include <glad/glad.h>
#include <unordered_map>

namespace Engine {
namespace Render {
// Individual shader program handle

class Shader {
    public:
        Shader(const std::string& shaderPath);
        ~Shader();

        void use();
        void deleteProgram();

        void cache(std::string path, std::string name);

        // TODO: send Uniform1/2/3 etc
        void setUniform1(std::string uniform, float x1);
        void setUniform2(std::string uniform, float x1, float x2);
        void setUniform3(std::string uniform, float x1, float x2, float x3);
    private:

        GLint getUniformLocation(std::string uniform);

        int _program;
        std::unordered_map<std::string, GLint> uniformCache;

};

} // namespace Render
} // namespace Engine
