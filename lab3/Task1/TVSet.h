#pragma once

class CTVSet
{
public:
	bool IsTurnedOn()const;
	void TurnOn();
	int GetChannel()const;

private:
	bool m_isOn = false;
};

