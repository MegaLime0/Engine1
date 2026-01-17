cmake_minimum_required(VERSION 4.1)

project(Engine
    VERSION 0.1
    DESCRIPTION "Small Experimental Game Engine"
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(engine src/main_temp.cpp)

target_include_directories(engine PRIVATE inc/)
target_include_directories(engine PRIVATE lib/)

target_link_libraries(engine PRIVATE SDL3)
