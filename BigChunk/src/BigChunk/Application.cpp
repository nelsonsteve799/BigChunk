#include "Application.h"

#include "BigChunk/Events/ApplicationEvent.h"
#include "BigChunk/Log.h"

namespace BigChunk {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			BC_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryApplication)) {
			BC_TRACE(e);
		}

		while (true);

	}

}