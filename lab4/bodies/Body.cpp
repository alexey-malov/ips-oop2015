#include "stdafx.h"
#include "Body.h"


CBody::CBody(double density)
	: m_density(density)
{
}

CBody::~CBody()
{
}

double CBody::GetDensity()const
{
	return m_density;
}

double CBody::GetMass()const
{
	return GetVolume() * GetDensity();
}

std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << GetType() << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}

void CBody::AppendProperties(std::ostream & strm) const
{
	strm;
}