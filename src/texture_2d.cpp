#include <engine/render/texture_2d.hpp>
#include <engine/render/base_texture.hpp>
#include <engine/loader.hpp>
#include <glad/glad.h>
#include <string>
#include <vector>

namespace engine {
namespace render {

Texture2D::Texture2D(std::string path) : BaseTexture(GL_TEXTURE_2D) {
    std::vector<unsigned char> image_data =
        Loader::loadImage(path, _w, _h, _channels);

    if (_channels != 4) {
        throw std::runtime_error("Image has more/less than 4 channels: " +
                                 std::string(path));
    }

    glGenTextures(1, &_glID);
    glBindTexture(_glTexType, _glID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _w, _h, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, image_data.data());

    _valid = true;
};

void Texture2D::deleteTexture() {
    glDeleteTextures(1, &_glID);
    _valid = false;
}

// TODO: fix this deleting logic
Texture2D::~Texture2D() {
    this->deleteTexture();
}

} // namespace render
} // namespace engine
