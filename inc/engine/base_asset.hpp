#pragma once

namespace engine {

class BaseAsset {
    public:
        void invalidate() { _valid = false; }

    protected:
        bool _valid;
};

} // namespace engine
