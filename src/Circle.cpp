
#include "pch.h"
#include "Circle.h"


shared_ptr<Base> constructCircle()
{
	return make_shared<Circle>();
}

const bool registered = shapePrototypeFactory::getInstance().registerShapeType("CIRCLE", constructCircle);


std::vector<std::shared_ptr<NVP>> Circle::searlize()
{
    std::vector<std::shared_ptr<NVP>> result;
	result.push_back(std::make_shared<NVP>("shape", "CIRCLE", "shape"));
	result.push_back(std::make_shared<NVP>("m_radius", to_string(m_radius),"int"));
	result.push_back(std::make_shared<NVP>("m_x", to_string(m_x),"float"));
	result.push_back(std::make_shared<NVP>("m_y", to_string(m_y),"float"));
	return result;
}


void Circle::deserialize(std::vector<std::shared_ptr<NVP>> ShapeVecValues)
{
	std::string::size_type size;

	for (std::shared_ptr<NVP> nvpObject : ShapeVecValues)
	{
		if (nvpObject->getType() == "float")
		{
			if (nvpObject->getName() == "m_x")
			{
				m_x = stof(nvpObject->getValue(), &size);
			}
			else if (nvpObject->getName() == "m_y")
			{
				m_y = stof(nvpObject->getValue(), &size);
			}
		}

		if (nvpObject->getType() == "int")
		{
			if (nvpObject->getName() == "m_radius")
			{
				m_radius = stoi(nvpObject->getValue(), &size);
			}
		}
	}

}