#pragma once

#include <glad/glad.h>

/* 
 * `Nearest`:               Scales texture pixel by pixel
 * `Linear`:                Scales texture linearly    
 * `NearestMipmapNearest`:  Closest mipmap, drawn using nearestNeighbor interpolation
 * `NearestMipmapLinear`:   Closest mipmap, drawn using linear interpolation
 * `LinearMipmapNearest`:   Two closest mipmaps interpolated, drawn using nearestNeighbor interpolation
 * `LinearMipmapLinear`:    Two closest mipmaps interplated, drawn using linear interpolation
*/
namespace Engine {
namespace TextureParameters {

enum class FilterMode { 
    Nearest,
    Linear,

    NearestMipmapNearest,
    NearestMipmapLinear,
    LinearMipmapNearest,
    LinearMipmapLinear,
};

enum class WrapMode { Repeat, MirroredRepeat, ClampToEdge, ClampToBorder };

struct Configuration {
    FilterMode MinFilter;
    FilterMode MagFilter;
    WrapMode WrapS;
    WrapMode WrapT;
};

inline GLuint filterToGL(FilterMode filter) {
    switch (filter) {
        case FilterMode::Nearest:
            return GL_NEAREST;
        case FilterMode::Linear:
            return GL_LINEAR;
        case FilterMode::NearestMipmapNearest:
            return GL_NEAREST_MIPMAP_NEAREST;
        case FilterMode::NearestMipmapLinear:
            return GL_NEAREST_MIPMAP_LINEAR;
        case FilterMode::LinearMipmapNearest:
            return GL_LINEAR_MIPMAP_NEAREST;
        case FilterMode::LinearMipmapLinear:
            return GL_LINEAR_MIPMAP_LINEAR;
    }
    return GL_NEAREST;
}

inline GLuint wrapToGL(WrapMode wrap) {
    switch (wrap) {
        case WrapMode::Repeat:
            return GL_REPEAT;
        case WrapMode::MirroredRepeat:
            return GL_MIRRORED_REPEAT;
        case WrapMode::ClampToEdge:
            return GL_CLAMP_TO_EDGE;
        case WrapMode::ClampToBorder:
            return GL_CLAMP_TO_BORDER;
    }

    return GL_REPEAT;
}

inline void setFiltering(GLenum target, GLuint id, FilterMode filterMin, FilterMode filterMag) {
    glBindTexture(target, id);
    glTexParameteri(target, GL_TEXTURE_MIN_FILTER, filterToGL(filterMin));
    glTexParameteri(target, GL_TEXTURE_MAG_FILTER, filterToGL(filterMag));
}

inline void setWrap(GLenum target, GLuint id, WrapMode wrapS, WrapMode wrapT) {
    glBindTexture(target, id);
    glTexParameteri(target, GL_TEXTURE_WRAP_S, wrapToGL(wrapS));
    glTexParameteri(target, GL_TEXTURE_WRAP_T, wrapToGL(wrapT));
}

} // namespace TextureParemeters
} // namespace Engine


