#ifndef MASS_AJ_H
#define MASS_AJ_H

#include "unit_aj.h"

class mass_aj : public unit_aj
{
	public:
		mass_aj();
		mass_aj(double initialValue);
		mass_aj(double initialValue, char unit);
		double getMass() const;
		double getMass(char unit) const;
		void setMass(double newValue);
		void setMass(double newValue, char unit);
		bool operator == (const mass_aj& ) const;
		bool operator != (const mass_aj& ) const;
		mass_aj& operator+=(const mass_aj &v);
		mass_aj& operator-=(const mass_aj &v);
		mass_aj operator+(const mass_aj& v) const;
		mass_aj operator-(const mass_aj& v) const;
		mass_aj operator*(const mass_aj& v) const;
		mass_aj operator/(const mass_aj& v) const;

	private:
		void setMassAsStone(double newValue);
		void setMassAslb(double newValue);
		double getMassAsStone() const;
		double getMassAslb() const;
};

#endif // MASS_AJ_H
