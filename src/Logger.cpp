#include "Logger.hpp"
#include <chrono>
#include <format>
#include <fstream>
#include <iostream>

namespace Logger {
	static std::string g_logPath;
	static std::ofstream g_logFile;

	static inline void Log(const std::string_view& prefix, const std::string_view& message);

	void Start(const std::string_view& path) {
		g_logPath = path;
		g_logFile = std::ofstream{ g_logPath };
		if (!g_logFile.is_open()) {
			std::cerr << "Failed to start logging!" << std::endl;
			std::terminate();
		}
	}

	void Stop() {
		g_logFile.close();
	}

	void Info(const std::string_view& message) {
		Log("INFO", message);
	}

	void Warning(const std::string_view& message) {
		Log("WARNING", message);
	}

	void Error(const std::string_view& message) {
		Log("ERROR", message);
	}

	static inline void Log(const std::string_view& prefix, const std::string_view& message) {
		std::string time = std::format("{:%Y-%m-%d %H:%M:%S}", std::chrono::system_clock::now());
		std::string fmtMessage = std::format("[{}][INFO] {}\n", time, message);

		std::cout << fmtMessage;
		g_logFile << fmtMessage;
	}
}