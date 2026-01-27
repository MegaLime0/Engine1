#pragma once
#include <string>

namespace engine {
// Individual shader program handle

class Shader {
    public:
        // TODO: add shader caching
        Shader(std::string vPath, std::string fPath);
        ~Shader();

        void use();
        void deleteProgram();
        void isValid();

        // TODO: send Uniform1/2/3 etc
    private:
        int _program;
        bool _valid; // set by deleteProgram, returned by isValid
};

}
