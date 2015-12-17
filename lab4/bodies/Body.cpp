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