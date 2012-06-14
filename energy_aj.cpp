#include "energy_aj.h"
#define CAL_CONVER_FAC 4184.0f //(kilo)calorie conversion factor
#define KJ_CONVER_FAC 1000.0f //kilojule conversion factor

energy_aj::energy_aj()
{
	this->value = 0;
}

energy_aj::energy_aj(double initialValue)
{
	this->value = initialValue;
}

energy_aj::energy_aj(double initialValue, char unit)
{
	if(unit == KILOJOULE)
	{    this->setEnergyAskj(initialValue); }
	else if(unit == CALORIE)
	{    this->setEnergyAsCal(initialValue);    }
	else
	{    this->setValue(initialValue);    }
}

void energy_aj::setEnergy(double newValue)
{
	this->setValue(newValue);
}

void energy_aj::setEnergy(double newValue, char unit)
{
	if(unit == KILOJOULE)
	{    this->setEnergyAskj(newValue); }
	else if(unit == CALORIE)
	{    this->setEnergyAsCal(newValue);    }
	else
	{    this->setValue(newValue);    }
}

double energy_aj::getEnergy() const
{
	return this->getValue();
}

QString energy_aj::getEnergyStr() const
{
	return QString::number(this->getValue());
}


double energy_aj::getEnergy(char unit) const
{
	if(unit == KILOJOULE)
	{    return this->getEnergyAskj();  }
	else if(unit == CALORIE)
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
	this->setValue(newValue*KJ_CONVER_FAC);
}

double energy_aj::getEnergyAsCal() const
{
	return this->value/CAL_CONVER_FAC;
}

void energy_aj::setEnergyAsCal(double newValue)
{
	this->setValue(newValue*CAL_CONVER_FAC);
}

bool energy_aj::operator== (const energy_aj& v) const
{
	return (this->getValue() == v.getValue());
}

bool energy_aj::operator!= (const energy_aj& v) const
{
	return (this->getValue() != v.getValue());
}

energy_aj& energy_aj::operator+=(const energy_aj &v)
{
	this->setValue(this->getValue() + v.getValue());

	return *this;
}

energy_aj& energy_aj::operator-=(const energy_aj &v)
{
	this->setValue(this->getValue() - v.getValue());

	return *this;
}

energy_aj energy_aj::operator +(const energy_aj& v) const
{
		energy_aj d(this->getValue() + v.getValue());
		return d;
}

energy_aj energy_aj::operator -(const energy_aj& v) const
{
		energy_aj d(this->getValue() - v.getValue());
		return d;
}

energy_aj energy_aj::operator *(const energy_aj& v) const
{
		energy_aj d(this->getValue() * v.getValue());
		return d;
}

energy_aj energy_aj::operator /(const energy_aj& v) const
{
		energy_aj d(this->getValue() / v.getValue());
		return d;
}
