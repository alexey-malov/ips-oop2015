#include "stdafx.h"
#include "../Sphere.h"


// Сфера
BOOST_AUTO_TEST_SUITE(Sphere)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		CSphere sphere;
		BOOST_CHECK_NO_THROW(dynamic_cast<CBody&>(sphere));
	}
BOOST_AUTO_TEST_SUITE_END()