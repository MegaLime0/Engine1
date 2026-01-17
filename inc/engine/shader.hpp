#pragma once
#include <string>

// Individual shader program handle

class Shader {
    public:
        Shader(std::string vPath, std::string fPath);

        void use();

        // TODO: send Uniform1/2/3 etc
    private:
        int _program;
};
