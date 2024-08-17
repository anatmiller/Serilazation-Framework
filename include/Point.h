#pragma once
#ifndef POINT_H
#define POINT_H
#include "Base.h"
#include "ArchiveBase.h"
#include "SeralizationHeader.h"
#include <stdio.h>
#include "SearlizeFactoryHandler.h"
#include "ShapePrototypeFactory.h"

class point :public Base
{
	protected:
		float m_x;
		float m_y;
		
   public:
	   //default constructor
	   point();

	   point(float c_x, float c_y);
	   
	   virtual ~point();


	   virtual std::vector<std::shared_ptr<NVP>> searlize() override;
	   virtual void deserialize(std::vector<std::shared_ptr<NVP>> ShapeVecValues) override;
	   
  

};

#endif // POINT_H
