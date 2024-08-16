#pragma once
#include "SerializationAlgorithm.h"
#include <fstream>  
#include <string>
#include <iostream>

class SerliazeJsonAlgo :public SerializationAlgorithm
{
public:
    SerliazeJsonAlgo() { ; }
    explicit SerliazeJsonAlgo(const std::string& fileName) : m_ofs(fileName)
    {
        if (!m_ofs.is_open()) {
            // Handle error, e.g., file couldn't be opened
            std::cerr << "Error: Unable to open file " << fileName << std::endl;
            // Handle the error appropriately, e.g., throw an exception or exit
        }
    }


    virtual bool serialize(const std::vector<std::shared_ptr<NVP>>& objects, string fileName) override;
    virtual bool deserialize(std::vector<std::shared_ptr<NVP>>& objects, string fileName) override;

    virtual ~SerliazeJsonAlgo() override { ; }

private:
    std::ofstream m_ofs;
};


