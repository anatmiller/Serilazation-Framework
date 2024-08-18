#include "pch.h"
#include "SerializeTextAlgo.h"
#include "SearlizeFactoryHandler.h"
#include "fstream"
#include "istream"
#include <fstream>
#include <string>
#include <sstream>

shared_ptr<SerializationAlgorithm> ConstructTextSerializer()
{
	return make_shared<SerializeText>();
}


const int registeredTypeDat = SearlizeFactoryHandler::getInstance().registerSerializationType(".dat", ConstructTextSerializer);
const int registeredTypeTxt = SearlizeFactoryHandler::getInstance().registerSerializationType(".txt", ConstructTextSerializer);


using namespace std;
bool SerializeText::deserialize(std::vector<std::vector<std::shared_ptr<NVP>>>& objectsVec, string fileName)
{
	std::ifstream inputFile(fileName);
	std::vector<std::shared_ptr<NVP>> objects;

	if (inputFile.is_open())
	{
		std::string line;
		std::string token;

		while (std::getline(inputFile, line))
		{
		
			std::istringstream iss(line);
			std::shared_ptr<NVP> shapeComponetsVec;
			std::vector<std::shared_ptr<NVP>> shapes;
			while (std::getline(iss, token,' '))
			{
				size_t n = token.find(":");
			
				if (n != std::string::npos) {
					std::string name = token.substr(0, n);
					std::string value = token.substr(n + 1);

					std::shared_ptr<NVP> newShape;
					newShape = std::make_shared<NVP>(name, value);
					shapes.push_back(newShape);
					
				}

			}


			objectsVec.push_back(shapes);
			
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
	for (std::vector<std::shared_ptr<NVP >> shapeVec: objectsShapeVec)
	{

		//outputFile << "type" << ": " << shapeVec[0]->getType() << std::endl;

		for (std::shared_ptr<NVP > nvp : shapeVec)
		{
			if (nvp)
			{
				outputFile << nvp->getName() << ":" << nvp->getValue() << "  ";
			}
		}
		outputFile << endl;
	
	}
	
	outputFile.close();
	return true;
}
