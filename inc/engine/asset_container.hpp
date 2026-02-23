#pragma once

#include "engine/base_asset.hpp"
#include <cstddef>
#include <vector>

namespace engine {

template<typename T>
class AssetContainer {

    static_assert(std::is_base_of_v<BaseAsset, T>, "Asset T should inherit BaseAsset");

    public:
        AssetContainer();

        std::size_t add(T asset);
        T get(std::size_t index);
        void remove(std::size_t index);

    private:
        std::vector<T> assets;
        std::vector<std::size_t> free_slots;
};


} // namespace engine
