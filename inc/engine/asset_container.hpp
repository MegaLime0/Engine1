#pragma once

#include "engine/base_asset.hpp"
#include <cstddef>
#include <vector>

namespace engine {

class AssetContainer {

    public:
        AssetContainer();

        std::size_t add(BaseAsset asset);
        BaseAsset get(std::size_t index);
        void remove(std::size_t index);

        void clear();

    private:
        std::vector<BaseAsset> assets;
        std::vector<std::size_t> free_slots;
};


} // namespace engine
