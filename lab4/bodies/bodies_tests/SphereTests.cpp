#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../Sphere.h"
#include <math.h>


struct Sphere_
{
	const double expectedRadius = 42.8;
	const double expectedDensity = 8.8;

	const CSphere sphere;
	Sphere_()
		: sphere(expectedDensity, expectedRadius)
	{}
};
// Сфера
BOOST_FIXTURE_TEST_SUITE(Sphere, Sphere_)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK_NO_THROW(dynamic_cast<const CBody&>(sphere));
	}
	// имеет радиус
	BOOST_AUTO_TEST_CASE(has_a_radius)
	{
		BOOST_CHECK_EQUAL(sphere.GetRadius(), expectedRadius);
	}
	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(sphere).GetDensity(), expectedDensity);
	}
	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{		
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(sphere).GetVolume(), 328412.68, 1e-7);
	}
BOOST_AUTO_TEST_SUITE_END()