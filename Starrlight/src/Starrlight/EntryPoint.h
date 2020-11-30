#pragma once

#ifdef SL_PLATFORM_WINDOWS

extern Starrlight::Application* Starrlight::CreateApplication();

int main(int argc, char** argv)
{
	Starrlight::Log::Init();

	auto app = Starrlight::CreateApplication();
	app->Run();
	delete app;
}

#endif