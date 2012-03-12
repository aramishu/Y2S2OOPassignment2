#include "energy_aj.h"
#define CAL_CONVER_FAC 4.18400f //calorie conversion factor
#define KJ_CONVER_FAC 1000.0f //kilojule conversion factor

energy_aj::energy_aj()
{
    this->value = 0;
}

energy_aj::energy_aj(double initialValue)
{
	this->value = initialValue;
}

energy_aj::energy_aj(double initialValue, char *unit)
{
	if(*unit == 'k')
	{    this->setEnergyAskj(initialValue); }
	else if(*unit == 'c')
	{    this->setEnergyAsCal(initialValue);    }
	else
	{    this->value = initialValue;    }
}

double energy_aj::getEnergy() const
{
	return this->getValue();
}

double energy_aj::getEnergy(char *unit) const
{
	if(*unit == 'k')
	{    return this->getEnergyAskj();  }
	else if(*unit == 'c')
	{    return this->getEnergyAsCal(); }
	else
	{    return this->getValue();    }
}

double energy_aj::getEnergyAskj() const
{
	return this->value/KJ_CONVER_FAC;
}

void energy_aj::setEnergyAskj(double newValue)
{
	this->value = newValue*KJ_CONVER_FAC;
}


double energy_aj::getEnergyAsCal() const
{
	return this->value/CAL_CONVER_FAC;
}

void energy_aj::setEnergyAsCal(double newValue)
{
	this->value = newValue*CAL_CONVER_FAC;
}
