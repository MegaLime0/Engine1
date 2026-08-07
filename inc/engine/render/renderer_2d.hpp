#pragma once

#include "engine/asset_manager.hpp"
#include "engine/configs.hpp"
#include "engine/render/camera_2d.hpp"
#include "engine/render/material.hpp"
#include <array>
#include <engine/asset_container.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/texture_2d.hpp>
#include <engine/render/texture_2d_array.hpp>
#include <engine/render/vertex.hpp>
#include <cstddef>
#include <glm/vec4.hpp>
#include <glm/vec2.hpp>

namespace Engine {
namespace Render {

class Renderer2D {
    public:
        // TODO: implement
        void init(Config::Render config, AssetManager& assets);
        void begin(const Camera2D& camera);
        void drawQuad(
                glm::vec2 pos,
                glm::vec2 size,
                Material material,
                glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        void end();

    private:
        void flush();

        AssetManager* assets = nullptr;

        static constexpr size_t MaxQuadsPerBatch = 512;
        static constexpr size_t MaxVerticesPerBatch = MaxQuadsPerBatch * 4;
        size_t verticeAmount = 0;

        std::array<SpriteVertex, MaxVerticesPerBatch> spriteVertices;
        GLuint vao, vbo, ebo;

        Camera2D cachedCamera;

        Shader* defaultShader = nullptr; 
        Shader* currentShader = nullptr;
        Shader* previousShader = nullptr;
        AssetHandler<Texture2D> currentTexture;
        AssetHandler<Texture2D> previousTexture;
};

} // namespace Render
} // namespace Engine
