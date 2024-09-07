#pragma once


#include <string>
#include<glm/glm.hpp>

namespace Kepeca
{
    class OpenGlObject
    {
    public:
        unsigned int ID;

        virtual void Bind();
        virtual void UnBind();

        virtual void Delete();
    };

	class VertexBufferObject : OpenGlObject
	{
    public:

        float* vertices;
        int size;

        //Size in bytes
        VertexBufferObject(float* vertices, int size);

        virtual void Bind() override;
        virtual void UnBind() override;
	};

	class VertexArrayObect : OpenGlObject
	{
    public:
        VertexArrayObect();

        virtual void Bind() override;
        virtual void UnBind() override;
	};

    class ElementBufferObject : OpenGlObject
    {
    public:
        int* indices;
        int size;

        //Size in bytes
        ElementBufferObject(int* indices, int size);

        virtual void Bind() override;
        virtual void UnBind() override;
    };

    class Shader : OpenGlObject
    {
    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        
        virtual void Bind() override;
        virtual void UnBind() override;

        void SetBool(const std::string& name, bool value) const;
        void SetInt(const std::string& name, int value) const;
        void SetFloat(const std::string& name, float value) const;
        void SetMat4(const std::string& name, glm::mat4 value) const;
        void SetVec3(const std::string& name, glm::vec3 value) const;

        void Delete() override;
    };

    class Texture : OpenGlObject
    {
    public:
        Texture(const char* path);

        virtual void Bind() override;
        virtual void UnBind() override;

        virtual void Delete() override;

    private:
        int m_Width = 0;
        int m_Height = 0;
        int m_NrChannels = 0;
    };
}