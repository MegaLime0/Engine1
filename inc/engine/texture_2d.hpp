#pragma once

#include <engine/base_texture.hpp>
#include <string>

namespace engine {

class Texture2D : protected BaseTexture{
    public:
        Texture2D(std::string path);
        ~Texture2D();

        void deleteTexture();
};




} // namespace engine
