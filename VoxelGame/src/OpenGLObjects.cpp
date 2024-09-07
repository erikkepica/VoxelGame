#include "OpenGLObjects.h"

#include<glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include<fstream>
#include <sstream>
#include"Log.h"

namespace Kepeca
{
    void OpenGlObject::Bind()
    {
    }
    void OpenGlObject::UnBind()
    {
    }
    void OpenGlObject::Delete()
    {
        glDeleteBuffers(1, &ID);
    }



    //---------------------------------
    //          SHADER
    //---------------------------------

    Shader::Shader(const char* vertexPath, const char* fragmentPath)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // open files
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure e)
        {
            LOG_ERROR("Vertex shader at: {0} ,couldn't be read!", vertexPath);
            LOG_ERROR("Fragment shader at: {0} ,couldn't be read!", fragmentPath);
        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        // 2. compile shaders
        unsigned int vertex, fragment;
        int success;
        char infoLog[512];

        // vertex Shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        // print compile errors if any
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            LOG_ERROR("Failed to compile fragment shader : {0}", infoLog);

        };

        // similiar for Fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        // print compile errors if any
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            LOG_ERROR("Failed to compile fragment shader : {0}", infoLog);
        };


        // shader Program
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        // print linking errors if any
        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            LOG_ERROR("Failed to link shader program: {0}", infoLog);
        }

        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void Shader::Bind() 
    {
        glUseProgram(ID);
    }

    void Shader::UnBind() 
    {
        glUseProgram(0);
    }

    void Shader::SetBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    void Shader::SetInt(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    void Shader::SetFloat(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
    void Shader::SetMat4(const std::string& name, glm::mat4 value) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }
    void Shader::SetVec3(const std::string& name, glm::vec3 value) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), value.x, value.y,value.z);
    }

    void Shader::Delete()
    {
        glDeleteProgram(ID);
    }

    //---------------------------------
    //          VBO
    //---------------------------------

    VertexBufferObject::VertexBufferObject(float* vertices, int size)
        :vertices(vertices), size(size)
    {
        glGenBuffers(1, &ID);
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }
    void VertexBufferObject::Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }
    void VertexBufferObject::UnBind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }




    //---------------------------------
    //          VAO
    //---------------------------------
    
    VertexArrayObect::VertexArrayObect()
    {
        glGenVertexArrays(1, &ID);

        Bind();

        //COORDS
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        //UV
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        //NORMAL
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
        glEnableVertexAttribArray(2);


    }

    void VertexArrayObect::Bind()
    {
        glBindVertexArray(ID);
    }

    void VertexArrayObect::UnBind()
    {
        glBindVertexArray(0);
    }

    //---------------------------------
    //          EBO
    //---------------------------------

    ElementBufferObject::ElementBufferObject(int* indices, int size)
        :indices(indices), size(size)
    {
        glGenBuffers(1, &ID);
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    }
    void ElementBufferObject::Bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    }
    void ElementBufferObject::UnBind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    //---------------------------------
    //          TEXTURE
    //---------------------------------
    
    Texture::Texture(const char* path)
    {
        unsigned char* data = stbi_load(path, &m_Width, &m_Height, &m_NrChannels, 0);

        glGenTextures(1, &ID);

        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }
    void Texture::Bind()
    {
        glBindTexture(GL_TEXTURE_2D, ID);
    }
    void Texture::UnBind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    void Texture::Delete()
    {
    }
}