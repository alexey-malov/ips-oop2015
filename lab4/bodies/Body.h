#pragma once
class CBody
{
public:
	CBody(double density);
	
	double GetDensity() const;
	virtual double GetVolume() const = 0;
	double GetMass() const;
	std::string ToString() const;

	virtual ~CBody();

protected:
	virtual std::string GetType() const = 0;
	virtual void AppendProperties(std::ostream & strm) const;

private:
	double m_density;
};

