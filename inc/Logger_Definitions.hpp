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
	/**
	 * The maximum number of letters in a string representation of a subsystem's name.
	 */
	inline constexpr uint8_t maximumLettersInSubsystemName = 5;

	/**
	 * The amount of options in the below enum class.
	 */
	inline constexpr uint8_t numberOfSubsystemOptions = 5;

	/**
	 * The subsystems that log messages originate from.
	 */
	enum class Subsystem : uint8_t {
		None = 0,
		OBC,
		COMMS,
		SU,
		ADCS
	};

	/**
	 * Map to assign enum's values to their string representations, for logging.
	 */
	static etl::map<Subsystem, String<maximumLettersInSubsystemName>, numberOfSubsystemOptions> subsystemToString = {
	    {Subsystem::None, "None"},
	    {Subsystem::OBC, "OBC"},
	    {Subsystem::COMMS, "COMMS"},
	    {Subsystem::SU, "SU"},
	    {Subsystem::ADCS, "ADCS"}};

	/**
	 * The subsystem to be used, if no other subsystem is defined using the stream operator.
	 */
	inline Subsystem currentSubsystem;
} // namespace LogSubsystem
