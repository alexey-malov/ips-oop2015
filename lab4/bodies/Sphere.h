#pragma once
#include "Body.h"

class CSphere final :
	public CBody
{
public:
	CSphere(double density, double radius);

	double GetRadius() const;
	double GetVolume() const override;

protected:
	std::string GetType() const override;
	void AppendProperties(std::ostream & strm) const override;

private:
	double m_radius;	
};
