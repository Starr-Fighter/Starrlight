#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Starrlight
{
	class STARRLIGHT_API Log
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

// Core log macros
#define SL_CORE_TRACE(...)    ::Starrlight::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SL_CORE_INFO(...)     ::Starrlight::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SL_CORE_WARN(...)     ::Starrlight::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SL_CORE_ERROR(...)    ::Starrlight::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SL_CORE_FATAL(...)    ::Starrlight::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SL_INFO(...)          ::Starrlight::Log::GetClientLogger()->info(__VA_ARGS__)
#define SL_WARN(...)          ::Starrlight::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SL_TRACE(...)         ::Starrlight::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SL_ERROR(...)         ::Starrlight::Log::GetClientLogger()->error(__VA_ARGS__)
#define SL_FATAL(...)         ::Starrlight::Log::GetClientLogger()->fatal(__VA_ARGS__)