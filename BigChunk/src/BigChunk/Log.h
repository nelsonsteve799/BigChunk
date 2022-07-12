#pragma once

#include "Core.h"
#include "spdlog\spdlog.h"

#include <memory>



namespace BigChunk {

	class BIGCHUNK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core Log Macros
#define BC_CORE_TRACE(...)    ::BigChunk::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BC_CORE_INFO(...)     ::BigChunk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BC_CORE_WARN(...)     ::BigChunk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BC_CORE_ERROR(...)    ::BigChunk::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BC_CORE_FATAL(...)    ::BigChunk::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define BC_TRACE(...)    ::BigChunk::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BC_INFO(...)     ::BigChunk::Log::GetClientLogger()->info(__VA_ARGS__)
#define BC_WARN(...)     ::BigChunk::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BC_ERROR(...)    ::BigChunk::Log::GetClientLogger()->error(__VA_ARGS__)
#define BC_FATAL(...)    ::BigChunk::Log::GetClientLogger()->fatal(__VA_ARGS__)