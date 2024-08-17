#include "pch.h"
#include "OutArchive.h"
#include "OutArchive.h"
#include <stdexcept>
#include <iostream>
#include "SeralizationHeader.h"
#include "SeralizationHeader.h"

OutArchive::OutArchive(const std::string& outputFileName) : ArchiveBase(outputFileName)
{
   
}

OutArchive::OutArchive() :ArchiveBase()
{

}

OutArchive::~OutArchive()
{

}

void OutArchive::write(vector<shared_ptr<Base>> objects)
{
    std::vector<std::vector<shared_ptr<NVP>>> resultObjects;
    

    for(shared_ptr<Base> shape :objects)
    {
       std::vector<shared_ptr<NVP>> object = shape->searlize();
       if (object.size() > 0)
       {
           resultObjects.push_back(object);
       }
      
    }

    m_SerializationAlgorithm->serialize(resultObjects, m_inputfilename);
  
}