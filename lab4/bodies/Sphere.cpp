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

std::string CSphere::ToString()const
{
	std::ostringstream strm;
	strm << "Sphere:" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl
		<< "\tradius = " << GetRadius() << std::endl;
	return strm.str();
}
