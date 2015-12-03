#pragma once

class CTVSet
{
public:
	bool IsTurnedOn()const;
	void TurnOn();

private:
	bool m_isOn = false;
};

