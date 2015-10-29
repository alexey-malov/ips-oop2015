#include "stdafx.h"
#include "Utils.h"

bool IsLeapYear(int year)
{
	return 
		(year % 100 == 0) ? false :
		(year % 4) == 0;
}