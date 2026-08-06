#pragma once

#include <engine/render/texture_parameters.hpp>
#include <engine/math/vector2d.hpp>
#include <string>

namespace Engine {
namespace Render {

class Texture2DArray {
    public:
        Texture2DArray(std::string path, TextureParameters::Configuration settings = {});
        ~Texture2DArray();

        GLuint getId() const { return _glID; }
        
        // TODO: implement vector3d 
        // Math::Vector2D getDimensions() const {
        //     return Math::Vector2D { 
        //         static_cast<float>(_width), 
        //         static_cast<float>(_height)
        //     };
        // }

        void setTextureParameters(TextureParameters::Configuration settings);

    private:
        GLuint _glID;
        float _width, _height, _depth, _channels;
};

} // namespace Render
} // namespace Engine
