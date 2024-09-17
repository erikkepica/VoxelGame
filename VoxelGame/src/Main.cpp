#include"Application.h"

int main()
{
	Kepeca::Application* app = new Kepeca::Application(Kepeca::AppSpecs{ (int)(1024 * 1.5),(int)(720 * 1.5),"Voxel Game" });
	app->Run();
	delete app;
}