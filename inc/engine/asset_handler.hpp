#include <cstdint>

namespace Engine {

template<typename T> struct AssetHandler {
    uint32_t id = 0;
    bool isValid() { return id != 0; }
};

} // namespace engine
