#include "pch.h"
#include "shapePrototypeFactory.h"
#pragma once
#include "Base.h"
#include "ShapePrototypeFactory.h"

bool  shapePrototypeFactory::registerShapeType(const std::string& type, CreateFunc func)
{
	getFactoryMap()[type] = func;
	return true;
}


std::shared_ptr<Base> shapePrototypeFactory::createShapeType(const std::string& type)
{
    std::string fType(type);

    std::unordered_map<std::string, CreateFunc> mp;
    mp = getFactoryMap();

    auto it = mp.find(type);
    if (it != mp.end()) {
        return it->second();
    }
    else
    {
        throw std::runtime_error("Type not found in extension list; it should be [.xml or .dat]: " + type);
    }

}


