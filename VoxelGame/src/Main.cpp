#include"Application.h"

int main()
{
	Kepeca::Application* app = new Kepeca::Application(Kepeca::AppSpecs{1024,720,"Voxel Game", .8f, .2f, .3f});
	app->Run();
	delete app;
}