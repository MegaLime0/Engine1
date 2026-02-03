#include <engine/base_texture.hpp>

namespace engine {

BaseTexture::BaseTexture(GLenum textureType) {
    _glTexType = textureType;
}

bool BaseTexture::isValid() {
    return _valid;
}

void BaseTexture::bind() {
    glBindTexture(_glTexType, _glID);
}

} // namespace engine
