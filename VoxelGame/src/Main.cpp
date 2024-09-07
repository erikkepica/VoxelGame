#include"Application.h"

int main()
{
	Kepeca::Application* app = new Kepeca::Application(Kepeca::AppSpecs{1024,720,"Voxel Game"});
	app->Run();
	delete app;
}