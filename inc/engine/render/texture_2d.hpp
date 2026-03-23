#pragma once

#include <engine/render/base_texture.hpp>
#include <string>

namespace engine {
namespace render {

class Texture2D : public BaseTexture {
    public:
        Texture2D(std::string path);
        ~Texture2D();

        void deleteTexture();
};


} // namespace render
} // namespace engine
