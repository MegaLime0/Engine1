#include <engine/render/base_texture.hpp>

namespace Engine {
namespace Render {

BaseTexture::BaseTexture(GLenum textureType) {
    _glTexType = textureType;
}

void BaseTexture::bind() {
    glBindTexture(_glTexType, _glID);
}

} // namespace render
} // namespace engine
