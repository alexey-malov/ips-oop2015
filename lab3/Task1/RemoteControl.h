#pragma once

class CTVSet;

class CRemoteControl
{
public:
	CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output);
	bool HandleCommand();
private:
	CTVSet & m_tv;
	std::istream & m_input;
	std::ostream & m_output;
};

