#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace BigChunk {

	class BIGCHUNK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool running = true;
	};

}