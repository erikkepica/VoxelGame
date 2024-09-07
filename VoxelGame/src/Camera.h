#pragma once
#include<glm/glm.hpp>
#include"Application.h"

namespace Kepeca
{
	class Camera
	{
	public:
		Camera(int fov, float aspectRatio, float zNear, float zFar, Application* app);
		
		glm::vec3 position;
		glm::vec3 rotation;
		
		void Update(glm::vec2 cursorPos);

		glm::mat4 GetProjection();
		glm::mat4 GetView();
		glm::mat4 GetOrbitView(glm::vec3 target);
	private:
		Application* m_App;

		int m_Fov;
		float m_AspectRatio;
		float m_ZNear;
		float m_ZFar;


		glm::vec2 m_LastCursorPos;
	};
}