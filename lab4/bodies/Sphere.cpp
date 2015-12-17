#include "stdafx.h"
#include "Sphere.h"


CSphere::CSphere(double density, double radius)
	: CBody(density)
	, m_radius(radius)
{
}

double CSphere::GetRadius()const
{
	return m_radius;
}

double CSphere::GetVolume()const
{
	return (pow(m_radius, 3) * M_PI) * 4 / 3;
}

std::string CSphere::GetType()const
{
	return "Sphere";
}

void CSphere::AppendProperties(std::ostream & strm) const
{
	CBody::AppendProperties(strm);
	strm << "\tradius = " << GetRadius() << std::endl;
}
