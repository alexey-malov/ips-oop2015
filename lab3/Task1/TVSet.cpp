#include "stdafx.h"
#include "TVSet.h"

bool CTVSet::IsTurnedOn()const
{
	return m_isOn;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}

int CTVSet::GetChannel()const
{
	if (m_isOn)
	{
		return 1;
	}
	return 0;
}
