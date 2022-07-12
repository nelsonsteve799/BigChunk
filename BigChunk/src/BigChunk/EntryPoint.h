#pragma once

#ifdef BC_PLATFORM_WINDOWS

extern BigChunk::Application* CreateApplication();

int main(int argc, char** argv) {

	int a = 5;

	BigChunk::Log::Init();
	BC_CORE_WARN("Initialized Log!");
	BC_INFO("Var = {0}", a);

	auto app = CreateApplication();
	app->Run();
	delete app;
}

#endif