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

        void setTextureParameter(GLenum glType, GLenum glValue);
        void setFiltering(GLenum glFiltering);
        void setWrap(GLenum glWrap);
};


} // namespace render
} // namespace engine
