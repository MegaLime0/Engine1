#include <engine/loader.hpp>
#include <engine/texture.hpp>
#include <stdexcept>
#include <vector>

namespace engine {

Texture::Texture(std::string tPath) {
    std::vector<unsigned char> image_data =
        Loader::loadImage(tPath, _width, _height, _channel_count);

    if (_channel_count != 4) {
        throw std::runtime_error("Image not in RGBA format: " +
                                 std::string(tPath));
    }

    glGenTextures(1, &_glID);
    glBindTexture(_glID, GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, image_data.data());

    _valid = true;
}

} // namespace engine
