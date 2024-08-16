#pragma once
#include "Base.h"

class shapePrototypeFactory
{
  public:
	using CreateFunc = std::shared_ptr<Base>(*)();

	static shapePrototypeFactory& getInstance() {
		static shapePrototypeFactory instance;
		return instance;
	}

	static std::unordered_map<std::string, CreateFunc>& getFactoryMap() {
		static std::unordered_map<std::string, CreateFunc> factoryMap;
		return factoryMap;
	}
	// Register a new serialization type
	static bool  registerShapeType(const std::string& type, CreateFunc func);

	static std::shared_ptr<Base> createShapeType(const std::string& type);

	shapePrototypeFactory(){}
};

