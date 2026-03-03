#pragma once

#include <engine/render/base_texture.hpp>
#include <string>

namespace engine {
namespace render {


class TextureAtlas2D : protected BaseTexture {
    public:
        TextureAtlas2D(std::string path);

    private:
        int _subW, _subH;
};


} // namespace render
} // namespace engine
