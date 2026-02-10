#include <engine/asset_container.hpp>

namespace engine {


template<typename T>
void AssetContainer<T>::add(T asset) {
    // TODO: implement adding
}

template<typename T>
T& AssetContainer<T>::get(std::size_t index) {
    std::size_t index_pointer = lookup_indices.at(index);
    AssetPointer<T> pointer = asset_pointers.at(index_pointer);
    return assets.at(pointer.asset_index);
}

template<typename T>
void AssetContainer<T>::remove(std::size_t index) {
    // TODO: implement removing
}



} // namespace engine

