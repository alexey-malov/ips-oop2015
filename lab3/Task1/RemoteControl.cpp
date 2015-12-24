#include "stdafx.h"
#include "RemoteControl.h"
#include "TVSet.h"

using namespace std;

CRemoteControl::CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
{
}

bool CRemoteControl::HandleCommand()
{
	string command;
	getline(m_input, command);
	if (command == "TurnOn")
	{
		m_tv.TurnOn();
		m_output << "TV is turned on" << endl;
	}
	else if (command == "TurnOff")
	{
		m_tv.TurnOff();
		m_output << "TV is turned off" << endl;
	}
	
	return true;
}
