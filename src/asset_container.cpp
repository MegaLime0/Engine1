#include <engine/asset_container.hpp>
#include <stdexcept>
#include <string>

namespace engine {

template<typename T>
AssetContainer<T>::AssetContainer() : assets(), free_slots() {
    // TODO: implement assetContainer constructor
}

template<typename T>
std::size_t AssetContainer<T>::add(T asset) {
    std::size_t asset_index;
    if (free_slots.size() != 0 ) {
        asset_index = free_slots.back();
        assets[asset_index] = asset;

        free_slots.pop_back();
    } else {
        assets.push_back(asset);
        asset_index = assets.size() - 1;
    }

    return asset_index;
}

template<typename T>
T AssetContainer<T>::get(std::size_t asset_index) {
    if (asset_index >= assets.size()) {
        throw std::runtime_error(
                "Asset index out of bounds: " 
                + std::to_string(asset_index)
                + " / "
                + std::to_string(assets.size() - 1));
    }

    return assets[asset_index];
}

template<typename T>
void AssetContainer<T>::remove(std::size_t asset_index) {
    if (asset_index >= assets.size()) {
        throw std::runtime_error(
                "Asset index out of bounds: " 
                + std::to_string(asset_index)
                + " / "
                + std::to_string(assets.size() - 1));
    }

    free_slots.push_back(asset_index);
    // TODO: asset isn't being invalidated
}

};
