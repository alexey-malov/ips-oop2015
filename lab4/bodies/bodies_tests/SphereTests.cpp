﻿#include "stdafx.h"
#include "../Sphere.h"


struct Sphere_
{
	const double expectedRadius = 42.8;
	const CSphere sphere;
	Sphere_()
		: sphere(expectedRadius)
	{}
};
// Сфера
BOOST_FIXTURE_TEST_SUITE(Sphere, Sphere_)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK_NO_THROW(dynamic_cast<const CBody&>(sphere));
	}
	BOOST_AUTO_TEST_CASE(has_a_radius)
	{
		BOOST_CHECK_EQUAL(sphere.GetRadius(), expectedRadius);
	}
BOOST_AUTO_TEST_SUITE_END()