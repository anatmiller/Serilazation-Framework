#pragma once
#ifndef INARCHIVE_H
#define INARCHIVE_H
/* InArchive is responsible deserializing objects from a binary file. 
   InArchive handles the deserialization of any object that dervis from base*/
#include <fstream>
#include "Base.h"
#include "ArchiveBase.h"

using namespace std;

class InArchive:ArchiveBase {
private:
    string m_inputFileName;

public:
    InArchive();
    InArchive(const std::string& filename);

    ~InArchive();

    void read(std::vector<std::shared_ptr<Base>>& shapeVec);

};

#endif