#include "BigChunkpch.h"
#include "Application.h"

#include "BigChunk/Events/ApplicationEvent.h"
#include "BigChunk/Log.h"

#include <GLFW/glfw3.h>

namespace BigChunk {

	Application::Application() {

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {

		while (running) {

			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();

		}

	}

}