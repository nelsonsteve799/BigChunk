#pragma once

#ifdef BC_PLATFORM_WINDOWS
	#ifdef BC_BUILD_DLL
		#define	BIGCHUNK_API __declspec(dllexport)
	#else
		#define	BIGCHUNK_API __declspec(dllimport)
	#endif
#else
	#error BigChunk only supports Windows!
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)