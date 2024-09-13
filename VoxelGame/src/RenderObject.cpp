#include "RenderObject.h"
#include <glm/gtc/matrix_transform.hpp>
#include"glad/glad.h"
#include"Log.h"

namespace Kepeca
{
	RenderObject::RenderObject()
	{

	}

	void RenderObject::Init(float* vertices, int vertSize, int* indices, int indSize, const char* vertShaderPath, const char* fragShaderPath, const char* texPath)
	{
		m_VBO = std::make_unique<VertexBufferObject>(vertices, vertSize);
		m_VAO = std::make_unique<VertexArrayObect>();
		m_EBO = std::make_unique<ElementBufferObject>(indices, indSize);

		m_Shader = std::make_unique<Shader>(vertShaderPath, fragShaderPath);
		m_Tex = std::make_unique<Texture>(texPath);

		position = glm::vec3(0.0f);
		rotation = glm::vec3(0.0f);
		scale = glm::vec3(1.0f);
	}

	void RenderObject::InitCamera(Camera* cam)
	{
		m_Cam = cam;
	}

	void RenderObject::Draw()
	{
		m_Shader->Bind();

		m_Shader->SetMat4("model", GetModelMat());
		m_Shader->SetMat4("view", m_Cam->GetView());
		m_Shader->SetMat4("projection", m_Cam->GetProjection());

		m_VAO->Bind();
		m_EBO->Bind();
		glDrawElements(GL_TRIANGLES, m_EBO->size/sizeof(float), GL_UNSIGNED_INT, 0);
	}

	VertexBufferObject* Kepeca::RenderObject::GetVBO()
	{
		return m_VBO.get();
	}

	VertexArrayObect* Kepeca::RenderObject::GetVAO()
	{
		return m_VAO.get();
	}

	ElementBufferObject* Kepeca::RenderObject::GetEBO()
	{
		return m_EBO.get();
	}
	Shader* RenderObject::GetShader()
	{
		return m_Shader.get();
	}
	Texture* RenderObject::GetTexture()
	{
		return m_Tex.get();
	}
	glm::mat4 RenderObject::GetModelMat()
	{
		glm::mat4 mat(1.0f);
		mat = glm::translate(mat, position);

		mat = glm::rotate(mat, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		mat = glm::rotate(mat, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		mat = glm::rotate(mat, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		
		mat = glm::scale(mat, scale);

		return mat;
	}
}

