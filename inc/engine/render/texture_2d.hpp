#pragma once

#include "engine/math/vector2d.hpp"
#include <string>
#include <glad/glad.h>
#include <engine/render/texture_parameters.hpp>

namespace Engine {
namespace Render {

class Texture2D {
    public:
        Texture2D(std::string path, TextureParameters::Configuration settings = {});
        ~Texture2D();

        GLuint getId() const { return _glID; }
        Math::Vector2D getDimensions() const {
            return Math::Vector2D { 
                static_cast<float>(_width), 
                static_cast<float>(_height)
            };
        }

        void setTextureParameters(TextureParameters::Configuration settings);

    private:
        GLuint _glID;
        int _width, _height, _channels; 
};


} // namespace render
} // namespace engine
