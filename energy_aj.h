#ifndef ENERGY_AJ_H
#define ENERGY_AJ_H

#include "unit_aj.h"
#include <QString>

class energy_aj : public unit_aj
{
public:
    energy_aj();
    energy_aj(double initialValue);
	energy_aj(double initialValue, char unit);
	double getEnergy() const;
	double getEnergy(char unit) const;
	QString getEnergyStr() const;
	void setEnergy(double newValue);
	void setEnergy(double newValue, char unit);
	bool operator == (const energy_aj& ) const;
	bool operator != (const energy_aj& ) const;
	energy_aj& operator+=(const energy_aj &v);
	energy_aj& operator-=(const energy_aj &v);

	energy_aj operator+(const energy_aj& v) const;
	energy_aj operator-(const energy_aj& v) const;
	energy_aj operator*(const energy_aj& v) const;
	energy_aj operator/(const energy_aj& v) const;

private:
	double getEnergyAskj(void) const;
	void setEnergyAskj(double newValue);
    double getEnergyAsCal(void) const;
    void setEnergyAsCal(double newValue);
};

#endif // ENERGY_AJ_H
