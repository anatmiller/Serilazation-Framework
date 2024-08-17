#include "pch.h"
#include "Point.h"



shared_ptr<Base> constructPoint()
{
	return make_shared<point>();
}

const bool registered = shapePrototypeFactory::getInstance().registerShapeType("POINT", constructPoint);


point::point(float x, float y) :Base(), m_x(x), m_y(y)
{
}

point::point():Base(),m_x(0.0f),m_y(0.0f)
{

}

std::vector<std::shared_ptr<NVP>> point::searlize()
{
	std::vector<std::shared_ptr<NVP>> resultObjects;
	resultObjects.push_back(std::make_shared<NVP>("shape", "point", "POINT"));
	resultObjects.push_back(std::make_shared<NVP>("m_x", to_string(m_x), "float"));
	resultObjects.push_back(std::make_shared<NVP>("m_y", to_string(m_y),"float"));
	return resultObjects;
}

void point::deserialize(std::vector<std::shared_ptr<NVP>> ShapeVecValues)
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
	
	}
}

point:: ~point() {
    //std::cout << "Point destructor called" << std::endl;
}

