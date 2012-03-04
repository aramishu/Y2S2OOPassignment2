#include "distance_aj.h"

#include <iostream>

distance_aj::distance_aj()
{
    this->distance = 5000;
}

distance_aj::distance_aj(double initialValue)
{
    this->distance = initialValue;
}

distance_aj::distance_aj(double initialValue, char *unit)
{
    if(*unit == 'k')
    {
       this->setDistanceAskm(initialValue);
    }
    else if(*unit == 'm')
    {
        this->setDistanceAsMiles(initialValue);
    }
}

double distance_aj::getDistance() const
{
    return this->distance;
}

double distance_aj::getDistance(char *unit) const
{
    if(*unit == 'k')
    {
        return this->getDistanceAsKm();
    }
    else if(*unit == 'm')
    {
        return this->getDistanceAsMiles();
    }
    else
    {   return this->distance;  }
}

void distance_aj::setDistance(double value)
{
    this->distance = value;
}

void distance_aj::setDistance(double value, char *unit)
{
    if(*unit == 'k')
    {
       this->setDistanceAskm(value);
    }
    else if(*unit == 'm')
    {
        this->setDistanceAsMiles(value);
    }
}

double distance_aj::getDistanceAsKm() const
{
    return this->distance/1000;
}

double distance_aj::getDistanceAsMiles() const
{
    return this->distance*0.000621371192f;
}

void distance_aj::setDistanceAskm(double newValue)
{
    this->distance = newValue*1000;
}

void distance_aj::setDistanceAsMiles(double newValue)
{
    this->distance = newValue/0.000621371192f;
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
    return (this->distance == v.getDistance());
}

bool distance_aj::operator!= (const distance_aj& v) const
{
    return (this->distance != v.getDistance());
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
