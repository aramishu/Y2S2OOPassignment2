#include "mass_aj.h"

#define STONE_CONVER_FAC 0.157473044f
#define POUND_CONVER_FAC 2.20462262f

mass_aj::mass_aj()
{
	this->setValue(0.0f);
}

mass_aj::mass_aj(double initialValue)
{
	this->setValue(initialValue);
}

mass_aj::mass_aj(double initialValue, char *unit)
{
	if(*unit == 'k')
	{	this->setValue(initialValue);	}
	else if(*unit == 's')
	{	this->setMassAsStone(initialValue);	}
	else if (*unit == 'b')
	{	this->setMassAslb(initialValue);	}
}

void mass_aj::setMassAsStone(double newValue)
{
	this->value = newValue/STONE_CONVER_FAC;
}

void mass_aj::setMassAslb(double newValue)
{
	this->value = newValue/POUND_CONVER_FAC;
}

double mass_aj::getMassAsStone() const
{
	return this->value*STONE_CONVER_FAC;
}

double mass_aj::getMassAslb() const
{
	return this->value*POUND_CONVER_FAC;
}

double mass_aj::getMass() const
{
	return	this->getValue();
}

double mass_aj::getMass(char *unit) const
{
	//if(*unit == 'k')
	//{	return this->getMass();	}
	//else
	if(*unit == 's')
	{	return this->getMassAsStone();	}
	else if (*unit == 'b')
	{	return this->getMassAslb();		}
	else
	{	return this->getMass();			}
}

void mass_aj::setMass(double newValue)
{
	this->setValue(newValue);
}

void mass_aj::setMass(double newValue, char *unit)
{
	if(*unit == 'k')
	{	this->setValue(newValue);		}
	else if(*unit == 's')
	{	this->setMassAsStone(newValue);	}
	else if (*unit == 'b')
	{	this->setMassAslb(newValue);	}
}

//-------------
bool mass_aj::operator == (const mass_aj& m) const
{
	return (this->getValue() == m.getValue());
}

bool mass_aj::operator != (const mass_aj& m) const
{
	return (this->getValue() != m.getValue());
}

mass_aj& mass_aj::operator+=(const mass_aj &v)
{
	this->setValue(this->getValue() + v.getValue());

	return *this;
}

mass_aj& mass_aj::operator-=(const mass_aj &v)
{
	this->setValue(this->getValue() - v.getValue());

	return *this;
}

mass_aj mass_aj::operator+(const mass_aj& v) const
{
	mass_aj d(this->getValue() + v.getValue());

	return d;
}

mass_aj mass_aj::operator-(const mass_aj& v) const
{
	mass_aj d(this->getValue() - v.getValue());

	return d;
}

mass_aj mass_aj::operator*(const mass_aj& v) const
{
	mass_aj d(this->getValue() * v.getValue());
	return d;
}

mass_aj mass_aj::operator/(const mass_aj& v) const
{
	mass_aj d(this->getValue() / v.getValue());
	return d;
}
