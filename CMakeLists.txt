cmake_minimum_required(VERSION 4.1)

project(Engine
    VERSION 0.1
    DESCRIPTION "Small Experimental Game Engine"
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(engine 
    src/main_temp.cpp 
    src/glad.c
    src/window.cpp
    src/loader.cpp 
    src/asset_container.cpp
    src/asset_manager.cpp 
    src/shader.cpp
    src/base_texture.cpp 
    src/texture_2d.cpp
    src/engine.cpp
    src/render/renderer.cpp
    src/render/quad.cpp
    src/render/base_render_object.cpp
    src/input/input.cpp
)

target_include_directories(engine BEFORE PRIVATE inc/)
target_include_directories(engine BEFORE PRIVATE lib/)

# for using the /extern SDL library
# add_subdirectory(extern/SDL) 
target_link_libraries(engine PRIVATE SDL3)
