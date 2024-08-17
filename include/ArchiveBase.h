#pragma once
#ifndef ARCHIVEBASE_H
#define ARCHIVEBASE_H

using namespace std;

#include "SerializationAlgorithm.h"
#include "SearlizeFactoryHandler.h"
#include "ArchiveBase.h"


#include <filesystem> 

using namespace std;
namespace fs = std::filesystem;


class ArchiveBase
{
	protected:
		string m_inputfilename;
		std::shared_ptr<SerializationAlgorithm> m_SerializationAlgorithm;

	public:
	
		ArchiveBase();
		ArchiveBase(string fileName);
		virtual ~ArchiveBase() {}
};

#endif