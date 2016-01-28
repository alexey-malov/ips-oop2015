#include "stdafx.h"
#include "../Triangle.h"

BOOST_AUTO_TEST_SUITE(Triangle)
	struct when_created_
	{
		CTriangle t = CTriangle(3, 4, 5);
	};
	BOOST_FIXTURE_TEST_SUITE(when_created, when_created_)
		BOOST_AUTO_TEST_CASE(has_three_sides)
		{
			BOOST_CHECK_EQUAL(t.GetSide1(), 3);
			BOOST_CHECK_EQUAL(t.GetSide2(), 4);
			BOOST_CHECK_EQUAL(t.GetSide3(), 5);
	}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()