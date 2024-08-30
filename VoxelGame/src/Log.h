#pragma once

#include"Core.h"
#include"spdlog/spdlog.h"


namespace Kepeca
{

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;

	};

}

// log macros
#define LOG_ERROR(...) ::Kepeca::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_WARN(...)  ::Kepeca::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_INFO(...)  ::Kepeca::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_TRACE(...) ::Kepeca::Log::GetLogger()->trace(__VA_ARGS__)

#ifdef CFG_DIST
#define LOG_INFO 
#endif // CFG_DIST
