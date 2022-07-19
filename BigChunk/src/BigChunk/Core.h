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

#define BIT(x) (1 << x)