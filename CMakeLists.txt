cmake_minimum_required(VERSION 4.1)

project(Engine
    VERSION 0.1
    DESCRIPTION "Small Experimental Game Engine"
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(engine 
    src/main_temp.cpp 
    src/glad.c
    src/window.cpp
    src/loader.cpp 
    src/shader.cpp
    src/texture_2d.cpp
    src/engine.cpp
    src/render/renderer_2d.cpp
)

target_include_directories(engine BEFORE PRIVATE inc/)
target_include_directories(engine BEFORE PRIVATE lib/)

# uncomment for using the /extern libraries
# add_subdirectory(extern/SDL) 
# add_subdirectory(extern/glm)

target_link_libraries(engine PRIVATE SDL3)
target_link_libraries(engine PRIVATE glm)
