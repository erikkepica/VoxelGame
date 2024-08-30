#pragma once

#include <string>

namespace Kepeca
{
    class Shader
    {
    public:
        // the program ID
        unsigned int ID;

        Shader(const char* vertexPath, const char* fragmentPath);
        // use/activate the shader
        void use();
        // utility uniform functions
        void setBool(const std::string& name, bool value) const;
        void setInt(const std::string& name, int value) const;
        void setFloat(const std::string& name, float value) const;
        //void setMat4(const std::string& name, glm::mat4 value) const;
        void Delete();
    };
}

