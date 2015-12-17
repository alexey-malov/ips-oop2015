#define _USE_MATH_DEFINES

#pragma once
#include "Body.h"
#include <math.h>

class CSphere final :
	public CBody
{
public:
	CSphere(double density, double radius);

	double GetRadius() const;
	virtual double GetVolume() const;

private:
	double m_radius;	
};

