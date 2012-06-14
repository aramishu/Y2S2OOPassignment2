#include "distance_aj.h"
#define KM_CON_FAC 1000.0f
#define M_CON_FAC 1609.344f

distance_aj::distance_aj()
{
	this->value = 0;
}

distance_aj::distance_aj(double initialValue)
{
	this->value = initialValue;
}

distance_aj::distance_aj(double initialValue, char unit)
{
	if(unit == KILOMETERS)
	{	this->setDistanceAskm(initialValue);	}
	else if(unit == MILES)
	{    this->setDistanceAsMiles(initialValue);	}
	else //if(unit == METERS)
	{	this->value = initialValue;	}
}

double distance_aj::getDistance() const
{
	//return this->value;
	return this->getValue();
}

double distance_aj::getDistance(char unit) const
{
	if(unit == KILOMETERS)
	{	return this->getDistanceAsKm();	}
	else if(unit == MILES)
	{	return this->getDistanceAsMiles();	}
	else
	{   return this->value;  }
}

void distance_aj::setDistance(double newValue)
{
	//this->value = value;
	this->setValue(newValue);
}

void distance_aj::setDistance(double value, char unit)
{
	if(unit == KILOMETERS)
	{	this->setDistanceAskm(value);	}
	else if(unit == MILES)
	{	this->setDistanceAsMiles(value);	}
	else
	{	this->setDistance(value);	}
}

double distance_aj::getDistanceAsKm() const
{
	return this->value/KM_CON_FAC;
}

double distance_aj::getDistanceAsMiles() const
{
	return this->value/M_CON_FAC;
}

void distance_aj::setDistanceAskm(double newValue)
{
	this->value = newValue*KM_CON_FAC;
}

void distance_aj::setDistanceAsMiles(double newValue)
{
	this->value = newValue*M_CON_FAC;
}

distance_aj distance_aj::operator +(const distance_aj& v) const
{
		distance_aj d(this->getDistance() + v.getDistance());
		return d;
}

distance_aj distance_aj::operator -(const distance_aj& v) const
{
		distance_aj d(this->getDistance() - v.getDistance());
		return d;
}

distance_aj distance_aj::operator *(const distance_aj& v) const
{
		distance_aj d(this->getDistance() * v.getDistance());
		return d;
}

distance_aj distance_aj::operator /(const distance_aj& v) const
{
		distance_aj d(this->getDistance() / v.getDistance());
		return d;
}

bool distance_aj::operator== (const distance_aj& v) const
{
	return (this->getValue() == v.getValue());
}

bool distance_aj::operator!= (const distance_aj& v) const
{
	return (this->getValue() != v.getValue());
}

distance_aj& distance_aj::operator+=(const distance_aj &v)
{
	this->setDistance(this->getDistance() + v.getDistance());

	return *this;
}

distance_aj& distance_aj::operator-=(const distance_aj &v)
{
	this->setDistance(this->getDistance() - v.getDistance());

	return *this;
}
