#pragma once

#include <glad/glad.h>

// TODO: implement TileMap class
namespace Engine {

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
