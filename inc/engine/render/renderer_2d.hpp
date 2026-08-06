#pragma once

#include "engine/asset_container.hpp"
#include "engine/render/shader.hpp"
#include "engine/render/texture_2d.hpp"
#include "engine/render/texture_2d_array.hpp"
#include "engine/render/vertex.hpp"
#include <cstddef>
#include <vector>

namespace Engine {
namespace Render {

class Renderer2D {
    public:

        // TODO: implement
        void init();
        void begin();
        void drawQuad();
        void drawTile();
        void end();

    private:
        void flush();

        static constexpr size_t MaxQuadsPerBatch = 500;
        std::vector<SpriteVertex> spriteVertices;
        std::vector<TileVertex> tileVertices;
        GLuint vao, vbo, ebo;

        Shader* currentShader = nullptr;
        AssetHandler<Texture2D> currentTexture;
        AssetHandler<Texture2DArray> currentTexArray;
};

} // namespace Render
} // namespace Engine
