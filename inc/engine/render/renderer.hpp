#pragma once

#include <engine/render/base_render_object.hpp>

namespace engine {
namespace render {

class Renderer {
    public:
        Renderer(int width, int height);

        void render(BaseRenderObject object);

        void resizeViewport(int width, int height);


    private:
};


} // namespace render
} // namespace engine
