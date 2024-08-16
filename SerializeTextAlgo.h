#pragma once
#include "SeralizationHeader.h"
#include "SerializationAlgorithm.h"

#include <fstream>  
#include <string>
#include <iostream>

using namespace std;

class SerializeText :public SerializationAlgorithm
{
    public:
       
        SerializeText() { ; }
        
        virtual bool serialize(const std::vector<std::vector<std::shared_ptr<NVP>>>& objects, string fileName) override;
        virtual bool deserialize(std::vector<std::vector<std::shared_ptr<NVP>>>& objects, string fileName) override;

        virtual ~SerializeText() { ; }
};

