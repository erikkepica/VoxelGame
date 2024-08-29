#include "Application.h"
#include"Log.h"

Kepeca::Application::Application()
{
}

Kepeca::Application::~Application()
{
}



void Kepeca::Application::Run()
{
	Kepeca::Log::Init();
	LOG_TRACE("Logger Initialized!");

	int a = 6;
	LOG_INFO("Var: {0}", a);

	while (true)
	{
	}
}
