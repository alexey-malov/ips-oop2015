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
// Телевизор 
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
	// изначально отображает 0 канал
	BOOST_AUTO_TEST_CASE(displays_channel_0_by_default)
	{
		BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
	}

	struct when_turned_on_ : TVSetFixture
	{
		when_turned_on_()
		{
			tv.TurnOn();
		}
	};
	// после включения
	BOOST_FIXTURE_TEST_SUITE(when_turned_on, when_turned_on_)
		// отображает канал 1
		BOOST_AUTO_TEST_CASE(displays_channel_one)
		{
			BOOST_CHECK_EQUAL(tv.GetChannel(), 1);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()