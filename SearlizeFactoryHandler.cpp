#include "pch.h"
#include "SearlizeFactoryHandler.h"
#include <stdexcept>  // For std::runtime_error


// Create a serialization handler based on the type
std::shared_ptr<SerializationAlgorithm> SearlizeFactoryHandler:: createSerialization(const std::string& type) {
        
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

bool SearlizeFactoryHandler:: registerSerializationType(const std::string& type, CreateFunc func) {
    getFactoryMap()[type] = func;
    return true;
}