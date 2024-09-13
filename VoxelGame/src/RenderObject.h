#pragma once
#include"OpenGLObjects.h"
#include<memory>
#include"Camera.h"

namespace Kepeca
{
	class RenderObject
	{
	public:

		RenderObject();

		void Init(float* vertices, int vertSize, int* indices, int indSize, const char* vertShaderPath, const char* fragShaderPath, const char* texPath);
		void InitCamera(Camera* cam);

		void Draw();


		VertexBufferObject* GetVBO();
		VertexArrayObect* GetVAO();
		ElementBufferObject* GetEBO();

		Shader* GetShader();
		Texture* GetTexture();

		glm::mat4 GetModelMat();

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

	private:
		std::unique_ptr<VertexBufferObject> m_VBO = nullptr;
		std::unique_ptr<VertexArrayObect> m_VAO = nullptr;
		std::unique_ptr<ElementBufferObject> m_EBO = nullptr;
		
		std::unique_ptr<Shader> m_Shader = nullptr;
		std::unique_ptr<Texture> m_Tex = nullptr;

		Camera* m_Cam = nullptr;
	};
}
