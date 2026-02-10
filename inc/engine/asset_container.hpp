#pragma once

#include <vector>

namespace engine {

template <typename T>
struct AssetPointer {
    std::size_t asset_index;
    std::size_t lookup_index;
};

template<typename T>
class AssetContainer {
    public:
        AssetContainer();

        void add(T asset);
        T& get(std::size_t index);
        void remove(std::size_t index);

    private:
        // basic structure:
        // lookup_indices -> asset_pointers
        // assets <- asset_pointers -> lookup_indices

        // stores values
        std::vector<T> assets;
        // stores indices to elements in "assets"
        std::vector<AssetPointer<T>> asset_pointers; 
        // stores indices to "asset_indices"
        std::vector<std::size_t> lookup_indices;
};


} // namespace engine
