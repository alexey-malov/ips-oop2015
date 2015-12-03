#pragma once

class CTVSet
{
public:
	bool IsTurnedOn()const;
	void TurnOn();
	void TurnOff();
	int GetChannel()const;

private:
	bool m_isOn = false;
};

