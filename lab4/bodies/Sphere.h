#pragma once
#include "Body.h"

class CSphere final :
	public CBody
{
public:
	CSphere(double density, double radius);

	double GetRadius() const;
	
private:
	double m_radius;
};

