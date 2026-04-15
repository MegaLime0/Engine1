#pragma once

#include <engine/base_asset.hpp>
#include <string>
#include <glad/glad.h>
#include <unordered_map>

namespace engine {
namespace render {
// Individual shader program handle

class Shader : protected BaseAsset {
    public:
        Shader(std::string vPath, std::string fPath);
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
        std::unordered_map<std::string, GLint> uniformCacheMap;

};

} // namespace render
} // namespace engine
