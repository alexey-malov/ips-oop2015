#include "stdafx.h"
#include "Triangle.h"
#include <stdexcept>
#include <string>

using namespace std;

const double & AssureNotNegative(const double & value, const string & argName = string())
{
	if (value >= 0)
	{
		return value;
	}
	throw invalid_argument(argName.empty() ? "Argument" : argName + " can not be negative.");
}

#define ASSURE_NOT_NEGATIVE(value) AssureNotNegative((value), #value)

CTriangle::CTriangle(double side1, double side2, double side3)
	: m_side1(ASSURE_NOT_NEGATIVE(side1))
	, m_side2(AssureNotNegative(side2, "Side 2"))
	, m_side3(AssureNotNegative(side3, "Side 3"))
{
}

double CTriangle::GetSide1()const
{
	return m_side1;
}

double CTriangle::GetSide2()const
{
	return m_side2;
}

double CTriangle::GetSide3()const
{
	return m_side3;
}
