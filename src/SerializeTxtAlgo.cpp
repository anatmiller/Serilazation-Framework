#include "pch.h"
#include "SerializeTextAlgo.h"
#include "SearlizeFactoryHandler.h"
#include "fstream"
#include "istream"

shared_ptr<SerializationAlgorithm> ConstructTextSerializer()
{
	return make_shared<SerializeText>();
}


const int registeredTypeDat = SearlizeFactoryHandler::getInstance().registerSerializationType(".dat", ConstructTextSerializer);
const int registeredTypeTxt = SearlizeFactoryHandler::getInstance().registerSerializationType(".txt", ConstructTextSerializer);



bool SerializeText::deserialize(std::vector<std::vector<std::shared_ptr<NVP>>>& objectsVec, string fileName)
{
	std::ifstream inputFile(fileName);
	std::vector<std::shared_ptr<NVP>> objects;
	std::string type = "";

	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{

			std::size_t delimiterPos = line.find(": ");
			if (delimiterPos != std::string::npos)
			{

				// Extract the name and the value from the line
				std::string name = line.substr(0, delimiterPos);
				std::string value = line.substr(delimiterPos + 2);

				// Create a new NVP object and add it to the vector
			   // Assuming NVP has a constructor that takes a name and a value
				objects.push_back(std::make_shared<NVP>(name, value, type));

			}

			objectsVec.push_back(objects);
		}

	}
	else
	{
		cout << "Failed to open file " << endl;
		//std::cerr << "Failed to open the file: " << fileName << std::endl;
	}
	return true;
}

bool SerializeText::serialize(const std::vector<std::vector<std::shared_ptr<NVP>>>& objectsShapeVec, string fileName)
{
	std::ofstream outputFile(fileName);
	for (std::vector<std::shared_ptr<NVP >> shapeVec : objectsShapeVec)
	{
		outputFile << "type" << ": " << shapeVec[0]->getType() << std::endl;

		for (std::shared_ptr<NVP > nvp : shapeVec)
		{
			if (nvp)
			{
				outputFile << nvp->getName() << ": " << nvp->getValue() << std::endl;
			}
		}

	}

	outputFile.close();
	return true;
}
