#pragma once
#include"Core.h"
#include"glad/glad.h"
#include<GLFW/glfw3.h>
#include<memory>
#include<string>


namespace Kepeca
{
	struct AppSpecs
	{
		int width;
		int height;

		std::string title;

		float r;
		float g;
		float b;
	};


	class Application
	{
	public:
		Application(AppSpecs specs);
		~Application();

		void Run();
	private:
		AppSpecs m_Specs;
		GLFWwindow* m_Window;
	};



}
