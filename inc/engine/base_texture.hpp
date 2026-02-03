#pragma once 

#include <glad/glad.h>

namespace engine {

class BaseTexture {
    public:
        BaseTexture(GLenum textureType);
        
        virtual void bind();
        virtual bool isValid();

        GLuint _glID;
        GLenum _glTexType;
        int _w, _h, _channels;
        bool _valid;
};

} // namespace engine
