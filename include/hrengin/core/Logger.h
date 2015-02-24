/*
 * Copyright (C) 2014-2015  absurdworlds
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _hrengin_Logger_
#define _hrengin_Logger_

#include <string>
#include <thread>

#include <hrengin/common/config.h>
#include <hrengin/common/macro.h>

#include <hrengin/core/core.h>

namespace hrengin {
namespace core {
/*1
 * Enumeration of all available log levels, to control
 * verbosity of logger output.
 */
enum class LogLevel {
	Default,
	Info,
	Debug,
	Warning,
	Error,
	Critical
};

/*!
 * This class provides interface for handling message logs, such as
 * streams and buffers, allowing to output into different targets 
 * simultaneously, e.g. into ingame console and stdout.
 */
class LogBook {
public:
	//! Write logger output
	virtual void log(std::string msg, LogLevel level) = 0;
};

/*!
 * This class provides interface for handling messages,
 * and sending them into different targets, which are
 * represented by LogBook class.
 */ 
class Logger {
public:
	/*!
	 * Set global logger (useful for debug output).
	 */
	static void setGlobalLogger(Logger* logger)
	{
		globalLogger = logger;
	}

	/*!
	 * Get pointer to global logger, which is set by setGlobalLogger()
	 */
	static Logger* getGlobalLogger()
	{
		return globalLogger;
	}

	static logGlobal(std::string const& msg,
			LogLevel logLevel = LogLevel::Default)
	{
		if (globalLogger) {
			globalLogger->push(msg, logLevel)
		}
	}

	static debugGlobal(std::string const& msg)
	{
#ifdef DEBUG
		if (globalLogger) {
			globalLogger->push(msg, LogLevel::DEBUG)
		}
#endif
	}

	//! Virtual destructor
	virtual ~Logger()
	{
	}

	/*!
	 * Write message to the log.
	 */
	virtual void push(std::string const& msg,
			LogLevel logLevel = LogLevel::Default) = 0;

	//! Add a recipient for the logger
	virtual void registerLog(LogBook* log) = 0;

	//! Remove recipient
	virtual void unregisterLog(LogBook* log) = 0;
private:
	// TODO: probably use std::unique_ptr?
	static Logger* globalLogger;
};

//! Create a logger instance
HR_CORE_EXP Logger* createLogger();

} // namespace core
} // namespace hrengin
#endif//_hrengin_Logger_