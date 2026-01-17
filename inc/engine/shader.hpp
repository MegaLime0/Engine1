#pragma once
#include <string>

namespace engine {
// Individual shader program handle

class Shader {
    public:
        Shader(std::string vPath, std::string fPath);
        ~Shader();

        void use();

        // TODO: send Uniform1/2/3 etc
    private:
        int _program;
};

}
