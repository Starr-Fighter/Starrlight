#include <Starrlight.h>

class Sandbox : public Starrlight::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Starrlight::Application* Starrlight::CreateApplication()
{
	return new Sandbox();
}