#pragma once

#include <glm/ext/matrix_float2x2.hpp>
#include <string>
#include <glad/glad.h>
#include <unordered_map>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace Engine {
namespace Render {
// Individual shader program handle

class Shader {
    public:
        Shader(const std::string& vPath, const std::string& fPath);
        ~Shader();

        void use();
        void deleteProgram();

        void cache(std::string path, std::string name);

        void setInt(std::string uniform, int v);
        void setBool(std::string uniform, bool v);

        void setUniform1(std::string uniform, float v);
        void setUniform2(std::string uniform, glm::vec2 v);
        void setUniform3(std::string uniform, glm::vec3 v);
        void setUniform4(std::string uniform, glm::vec4 v);

        void setMatrix2(std::string uniform, glm::mat2 m);
        void setMatrix3(std::string uniform, glm::mat3 m);
        void setMatrix4(std::string uniform, glm::mat4 m);

    private:

        GLint getUniformLocation(std::string uniform);

        uint32_t _program;
        std::unordered_map<std::string, GLint> uniformCache;

};

} // namespace Render
} // namespace Engine
