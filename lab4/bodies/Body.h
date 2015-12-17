#pragma once
class CBody
{
public:
	CBody(double density);
	
	double GetDensity() const;

	virtual ~CBody();

private:
	double m_density;
};

