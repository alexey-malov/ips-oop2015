#include "stdafx.h"
#include "../Task1/RemoteControl.h"
#include "../Task1/TVSet.h"
#include <sstream>

using namespace std;

// Зависимости RemoteControl-а вынесены в родительскую структуру,
// чтобы гарантировать их создание до конструирования самого remote-контрола
struct RemoteControlDependencies
{
	CTVSet tv;
	stringstream input;
	ostringstream output;
};

struct RemoteControlFixture : RemoteControlDependencies
{
	CRemoteControl remoteControl;
	
	RemoteControlFixture()
		: remoteControl(tv, input, output)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Remote_Control, RemoteControlFixture)

	BOOST_AUTO_TEST_CASE(can_handle_TurnOn_command)
	{
		input << "TurnOn";
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK(tv.IsTurnedOn());
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), "TV is turned on\n");
	}

	BOOST_AUTO_TEST_CASE(can_turn_off_tv_which_is_on)
	{
		tv.TurnOn();
		input << "TurnOff";
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK(!tv.IsTurnedOn());
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), "TV is turned off\n");
	}

BOOST_AUTO_TEST_SUITE_END()