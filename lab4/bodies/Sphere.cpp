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