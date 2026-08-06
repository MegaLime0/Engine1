#include <engine/render/texture_parameters.hpp>
#include <engine/render/texture_2d.hpp>
#include <engine/loader.hpp>
#include <glad/glad.h>
#include <string>
#include <vector>

namespace Engine {
namespace Render {

Texture2D::Texture2D(std::string path, TextureParameters::Configuration settings) {
    std::vector<unsigned char> image_data =
        Loader::loadImage(path, _width, _height, _channels);

    if (_channels != 4) {
        throw std::runtime_error("Image has more/less than 4 channels: " +
                                 std::string(path));
    }

    // create buffer for texture on gpu
    glGenTextures(1, &_glID);
    glBindTexture(GL_TEXTURE_2D, _glID);

    setTextureParameters(settings);

    // send texture data to gpu
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, image_data.data());

};

void Texture2D::setTextureParameters(TextureParameters::Configuration settings) {
    TextureParameters::setFiltering(GL_TEXTURE_2D, _glID, settings.MinFilter, settings.MagFilter);
    TextureParameters::setWrap(GL_TEXTURE_2D, _glID, settings.WrapS, settings.WrapT);
}

Texture2D::~Texture2D() {
    glDeleteTextures(1, &_glID);
}

} // namespace render
} // namespace engine
