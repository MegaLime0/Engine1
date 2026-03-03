#pragma once 

#include <engine/base_asset.hpp>
#include <glad/glad.h>

namespace engine {
namespace render {

class BaseTexture : protected BaseAsset {
    public:
        BaseTexture(GLenum textureType);

        // TODO: override this deleteTexture() method somehow
        virtual void deleteTexture();

        void bind();

        // TODO: move these to private
        GLuint _glID;
        GLenum _glTexType;
        int _w, _h, _channels;
};

} // namespace render
} // namespace engine
