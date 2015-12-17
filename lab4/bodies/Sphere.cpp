#include "stdafx.h"
#include "Sphere.h"


CSphere::CSphere(double radius)
	: m_radius(radius)
{
}

double CSphere::GetRadius()const
{
	return m_radius;
}