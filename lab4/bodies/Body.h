#pragma once
class CBody
{
public:
	CBody(double density);
	
	double GetDensity() const;
	virtual double GetVolume() const = 0;
	double GetMass() const;

	virtual ~CBody();

private:
	double m_density;
};

