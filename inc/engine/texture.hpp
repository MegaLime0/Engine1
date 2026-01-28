#pragma once

#include <glad/glad.h>
#include <string>

// TODO: implement Texture class
namespace engine {

class Texture {
    public:
        Texture(std::string tPath);
        ~Texture();

        void deleteTexture();
        bool isValid();

    private:
        int _width, _height, _channel_count;
        GLuint _glID;
        bool _valid;
};

}
