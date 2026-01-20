#pragma once

#include <glad/glad.h>

// TODO: implement TileMap class
namespace engine {

class TileMap {
    public:
        TileMap();
        ~TileMap();

        void deleteTileMap();
        bool isValid();
    private:
        GLuint _glID;
        bool _valid;
};

}
