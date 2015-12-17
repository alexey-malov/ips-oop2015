#pragma once
class CBody
{
public:
	CBody(double density);
	
	double GetDensity() const;
	virtual double GetVolume() const = 0;
	double GetMass() const;
	virtual std::string ToString() const = 0;

	virtual ~CBody();

private:
	double m_density;
};

