#pragma once
#include "vector"

#include "SeralizationHeader.h"
#include <iostream>
#include <fstream>

using namespace std;

class SerializationAlgorithm
{

public:
	SerializationAlgorithm() { ; }
	virtual ~SerializationAlgorithm() { ; }
	virtual bool serialize(const std::vector<std::vector<std::shared_ptr<NVP>>>& objects, string fileName) = 0;
	virtual bool deserialize(std::vector<std::vector<std::shared_ptr<NVP>>>& objects, string fileName)=0;
};

