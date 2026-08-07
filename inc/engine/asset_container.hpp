#pragma once

#include <cstdint>
#include <unordered_map>
#include <string>
#include <vector>
#include <engine/asset_handler.hpp>

namespace Engine {
template<typename T> class AssetContainer {
    public:
        // TODO: add list initialization of assets (multiple assets in one function call)
        /// @param path can be used as an "identifier" to find the asset later
        /// @param T&& means that T is used as an rvalue reference (temp object)
        AssetHandler<T> load(const std::string& path, T&& asset) {
            // check if asset is already cached and return it
            auto assetId = assetPathId.find(path);
            if (assetId != assetPathId.end()) {
                return AssetHandler<T> { assetId->second };
            }

            // std::move moves the asset ownership to vector (T&& makes asset be an rvalue (temp object))
            assets.push_back(std::move(asset));
            return AssetHandler<T> { static_cast<uint32_t>(assets.size()) };
        }

        /// return the asset by using its handle
        T* get(AssetHandler<T> handle) {
            if (!handle.isValid() || handle.id > assets.size()) {
                return nullptr;
            }

            return &assets[handle.id - 1];
        }

    private:
        // indexed by id
        std::vector<T> assets;
        std::unordered_map<std::string, uint32_t> assetPathId;
};

} // namespace engine
