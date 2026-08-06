#pragma once

namespace Engine {

class BaseAsset {
    public:
        void invalidate() { _valid = false; }

    protected:
        bool _valid;
};

} // namespace engine
