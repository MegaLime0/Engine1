#pragma once

#include <engine/base_asset.hpp>
#include <string>

namespace engine {
namespace render {
// Individual shader program handle

class Shader : protected BaseAsset {
    public:
        // TODO: add shader caching
        Shader(std::string vPath, std::string fPath);
        ~Shader();

        void use();
        void deleteProgram();

        // TODO: send Uniform1/2/3 etc
    private:
        int _program;
};

} // namespace render
} // namespace engine
