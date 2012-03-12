#ifndef ENERGY_AJ_H
#define ENERGY_AJ_H

#include "unit_aj.h"

class energy_aj : public unit_aj
{
public:
    energy_aj();
    energy_aj(double initialValue);
	energy_aj(double initialValue, char *unit);
	double getEnergy() const;
	double getEnergy(char *unit) const;

private:
	double getEnergyAskj(void) const;
	void setEnergyAskj(double newValue);
    double getEnergyAsCal(void) const;
    void setEnergyAsCal(double newValue);
};

#endif // ENERGY_AJ_H
