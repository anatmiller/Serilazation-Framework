#pragma once

#include "SerializationAlgorithm.h"


class SearlizeFactoryHandler
{
public:
	using CreateFunc = std::shared_ptr<SerializationAlgorithm>(*)();
	static SearlizeFactoryHandler& getInstance() {
		static SearlizeFactoryHandler instance;
		return instance;
	}


	// Register a new serialization type
	static bool  registerSerializationType(const std::string& type, CreateFunc func);

	static std::shared_ptr<SerializationAlgorithm> createSerialization(const std::string& type);

	~SearlizeFactoryHandler() { ; }

private:
	SearlizeFactoryHandler() = default;

	SearlizeFactoryHandler(const SearlizeFactoryHandler&) = delete;

	SearlizeFactoryHandler& operator=(const SearlizeFactoryHandler&) = delete;

	static std::unordered_map<std::string, CreateFunc>& getFactoryMap() {
		static std::unordered_map<std::string, CreateFunc> factoryMap;
		return factoryMap;
	}
};

