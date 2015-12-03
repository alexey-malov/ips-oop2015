#include "stdafx.h"
#include "../Task1/TVSet.h"

/*
Телевизор
	изначально выключен
*/

struct TVSetFixture
{
	CTVSet tv;
};

BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)
	// изначально выключен
	BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
	{
		BOOST_CHECK(!tv.IsTurnedOn());
	}
	// может быть включен
	BOOST_AUTO_TEST_CASE(can_be_turned_on)
	{
		tv.TurnOn();
		BOOST_CHECK(tv.IsTurnedOn());
	}
BOOST_AUTO_TEST_SUITE_END()