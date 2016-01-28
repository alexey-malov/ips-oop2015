#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(double side1, double side2, double side3)
	: m_side1(side1)
	, m_side2(side2)
	, m_side3(side3)
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
