#include <Logger.hpp>
#include "Time/UTCTimestamp.hpp"

etl::format_spec Logger::format;

// Reimplementation of the function for variable C strings
template <>
Logger::LogEntry& Logger::LogEntry::operator<<(char* value) {
	message.append(value);
	return *this;
}

// Reimplementation of the function for C strings
template <>
Logger::LogEntry& Logger::LogEntry::operator<<(const char* value) {
	message.append(value);
	return *this;
}

Logger::LogEntry::LogEntry(LogLevel level) : level(level) {}

Logger::LogEntry::~LogEntry() {
	// When the destructor is called, the log message is fully "designed". Now we can finally "display" it to the user.
	Logger::log(level, message);
}

Logger::LogEntry& operator<<(Logger::LogEntry& entry, const UTCTimestamp &time) {
    // ...
    etl::string<29> printTime = "Time:";
    etl::to_string(time.hour, printTime, true);
    printTime += "-";
    etl::to_string(time.minute, printTime, true);
    printTime += "-";
    etl::to_string(time.second, printTime, true);
    printTime += " -- ";
    etl::to_string(time.day, printTime, true);
    printTime += "/";
    etl::to_string(time.month, printTime, true);
    printTime += "/";
    etl::to_string(time.year, printTime, true);

    entry.message += printTime.data();
    return entry;
}