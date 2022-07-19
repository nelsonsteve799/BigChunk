#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace BigChunk {

	class BIGCHUNK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

}