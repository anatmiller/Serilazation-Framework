#include "pch.h"
#include "InArchive.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "shapePrototypeFactory.h"

using namespace std;

// Constructor
InArchive::InArchive(const std::string& filename) :ArchiveBase(filename)
{
    
}

InArchive::InArchive() :ArchiveBase()
{

}

InArchive::~InArchive()
{

}

void InArchive::read(std::vector<std::shared_ptr<Base>>&shapeVec)
{
    std::vector<std::vector<std::shared_ptr<NVP>>> resultObjects;
    shapePrototypeFactory shapeFactory = shapePrototypeFactory::getInstance();

    m_SerializationAlgorithm->deserialize(resultObjects, m_inputfilename);
    for (std::vector<std::shared_ptr<NVP>> shapeMemberstypeValues: resultObjects)
    {
        std::string shapeType = shapeMemberstypeValues[0]->getType();
        shared_ptr<Base> curShape = shapeFactory.createShapeType(shapeType);
        shapeVec.push_back(curShape);
        curShape->deserialize(shapeMemberstypeValues);
    }
}


