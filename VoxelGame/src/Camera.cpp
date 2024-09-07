#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Kepeca
{
	Camera::Camera(int fov, float aspectRatio, float zNear, float zFar, Application* app)
		:m_Fov(fov), m_AspectRatio(aspectRatio), m_ZNear(zNear), m_ZFar(zFar), position(0,0,0), rotation(0,0,0), m_LastCursorPos(500,500), m_App(app)
	{
	}

	void Camera::Update(glm::vec2 cursorPos)
	{
		float xoffset = cursorPos.x - m_LastCursorPos.x;
		float yoffset = m_LastCursorPos.y - cursorPos.y; // reversed since y-coordinates range from bottom to top
		m_LastCursorPos.x = cursorPos.x;
		m_LastCursorPos.y = cursorPos.y;

		const float sensitivity = 0.1f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		rotation += glm::vec3(-yoffset, xoffset, 0);

		glm::vec3 forward = glm::vec3(glm::inverse(GetView())[2]);
		glm::vec3 up = glm::vec3(0, 1, 0);
		glm::vec3 right = -glm::normalize(glm::cross(up, forward));

		if (glfwGetKey(m_App->GetWindow(), GLFW_KEY_W))
		{
			position += glm::vec3(forward.x, 0, forward.z) *0.2f;
		}
		if (glfwGetKey(m_App->GetWindow(), GLFW_KEY_A))
		{
			position += glm::vec3(right.x, 0, right.z) * -0.2f;
		}
		if (glfwGetKey(m_App->GetWindow(), GLFW_KEY_S))
		{
			position += glm::vec3(forward.x, 0, forward.z) * -0.2f;
		}
		if (glfwGetKey(m_App->GetWindow(), GLFW_KEY_D))
		{
			position += glm::vec3(right.x, 0, right.z) * 0.2f;
		}
		if (glfwGetKey(m_App->GetWindow(), GLFW_KEY_SPACE))
		{
			position += up * -0.2f;
		}
		if (glfwGetKey(m_App->GetWindow(), GLFW_KEY_LEFT_SHIFT))
		{
			position += up * 0.2f;
		}
	}

	glm::mat4 Camera::GetProjection()
	{
		return glm::perspective((float)m_Fov, m_AspectRatio, m_ZNear, m_ZFar);
	}

	glm::mat4 Camera::GetView()
	{
		glm::mat4 view(1.0f);

		view = glm::rotate(view, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		view = glm::rotate(view, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		view = glm::rotate(view, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		
		view = glm::translate(view, position);

		return view;
	}

	glm::mat4 Camera::GetOrbitView(glm::vec3 target)
	{
		glm::mat4 view(1.0f);

		view = glm::lookAt(position, target, glm::vec3(0, 1, 0));

		return view;
	}

}
