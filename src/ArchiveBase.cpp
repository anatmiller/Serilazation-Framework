
#include "pch.h"
#include "ArchiveBase.h"



// Forward declaration of the Factory class
//class SerializationFactory;

//Constuctor input parameer: recieve fileName 
ArchiveBase::ArchiveBase(string fileName)
{
	m_inputfilename = fileName;
	fs::path filePath(m_inputfilename);
	std::string fileNameExtension = filePath.extension().string();
	SearlizeFactoryHandler& factory = SearlizeFactoryHandler::getInstance();
	m_SerializationAlgorithm=factory.createSerialization(fileNameExtension);

}

ArchiveBase::ArchiveBase()
{

}
