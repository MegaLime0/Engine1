#pragma once
#include "engine/render/base_render_object.hpp"
#include <SDL3/SDL.h>

namespace engine {

class Renderer {
    public:
        Renderer();

        void render(render::BaseRenderObject object);
    private:
};

} // namespace engine
