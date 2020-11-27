#pragma once

#ifdef SL_PLATFORM_WINDOWS
	#ifdef SL_BUILD_DLL
		#define STARRLIGHT_API __declspec(dllexport)
	#else
		#define STARRLIGHT_API __declspec(dllimport)
	#endif
#else
	#error Starrlight only supports Windows!
#endif