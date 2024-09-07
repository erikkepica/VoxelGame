#pragma once
#include"Core.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<memory>
#include<string>

namespace Kepeca
{
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	struct AppSpecs
	{
		int width;
		int height;

		std::string title;
	};


	class Application
	{
	public:
		Application(AppSpecs specs);
		~Application();

		void Run();
		
		GLFWwindow* GetWindow();
	private:
		AppSpecs m_Specs;
		GLFWwindow* m_Window;
	};
}
