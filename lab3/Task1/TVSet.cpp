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
	return 0;
}
