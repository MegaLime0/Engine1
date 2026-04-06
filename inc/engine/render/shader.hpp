#pragma once

#include <engine/base_asset.hpp>
#include <string>

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
    private:
        int _program;
};

} // namespace render
} // namespace engine
