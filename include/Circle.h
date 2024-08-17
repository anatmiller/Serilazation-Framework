#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "SeralizationHeader.h"
#include <string>
/**class Triangle :public point {



};*/

class Circle :public point {

private:
    int m_radius; // Radius of the circle

public:
    // Default constructor
    Circle() : point(), m_radius(0) {}
    Circle(float cord_x,float cord_y,int radius):point(cord_x, cord_y), m_radius(radius) {}
   
    virtual std::vector<std::shared_ptr<NVP>> searlize() override;
    virtual void deserialize(std::vector<std::shared_ptr<NVP>> ShapeVecValues) override;


    virtual ~Circle() { ; }
};

#endif // CIRCLE_H
