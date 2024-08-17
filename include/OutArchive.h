#pragma once
#ifndef OUTARCHIVE_H
#define OUTARCHIVE_H

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "Base.h"
#include "ArchiveBase.h"

using namespace std;

class OutArchive :ArchiveBase
{
public:
    OutArchive(const std::string& filename);
    OutArchive();
    ~OutArchive();
    void write(vector<shared_ptr<Base>> objects);
};

#endif // OUTARCHIVE_H
