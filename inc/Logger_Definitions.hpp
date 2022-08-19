#pragma once

#include "etl/String.hpp"
#include "etl/map.h"

/**
 * @defgroup LoggerDefinitions ECSS Defined Constants
 *
 * This file contains constant definitions that are used in the logger configuration.
 *
 * @todo All these constants need to be redefined and revised after the design and the requirements are finalized.
 *
 * @{
 */

/**
 * @file
 * This file contains constant definitions that are used in the logger configuration.
 * @see LoggerDefinitions
 */

/**
 * @brief The maximum size of a log message
 */
#define LOGGER_MAX_MESSAGE_SIZE 512

namespace LogSubsystem {
	enum class Subsystem : uint8_t {
		None = 0,
		OBC,
		COMMS,
		SU,
		ADCS
	};

	static etl::map<Subsystem, String<5>, 5> subsystemToString = {
	    {Subsystem::None, "None"},
	    {Subsystem::OBC, "OBC"},
	    {Subsystem::COMMS, "COMMS"},
	    {Subsystem::SU, "SU"},
	    {Subsystem::ADCS, "ADCS"}};

	inline Subsystem currentSubsystem;
}
