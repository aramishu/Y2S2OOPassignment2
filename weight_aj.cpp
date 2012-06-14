#include "weight_aj.h"

weight_aj::weight_aj()
{
	//this->mass = mass_aj(0.0f);
	//this->time = QTime(0, 0, 0, 0);
	this->time = QTime::currentTime();
}

weight_aj::~weight_aj()
{}

weight_aj::weight_aj(double massValue, QString strTime)
{
	this->mass = mass_aj(massValue);
	this->time = QTime::fromString(strTime, "hhmmsszzz");//hh:mm:ss:zzz where z = miliseconds
}

weight_aj::weight_aj(QString massValue, QString strTime)
{
	this->mass = mass_aj(massValue.toDouble());
	this->time = QTime::fromString(strTime, "hhmmsszzz");//hh:mm:ss:zzz where z = miliseconds
}

double weight_aj::getMass() const
{
	return this->mass.getMass();
}

double weight_aj::getMass(char unit) const
{
	return this->mass.getMass(unit);
}

QString weight_aj::getMassStr() const
{
	return QString::number(this->mass.getMass());
}

QTime weight_aj::getTime() const
{
	return this->time;
}

QString weight_aj::getTimeString() const
{
	return this->time.toString("hh:mm:ss");//("hh:mm:ss.zzz");
}

int weight_aj::getTimeInt() const
{
	return this->time.toString("hhmmsszzz").toInt();
}

QString weight_aj::getTimeStr() const
{
	return this->time.toString("hhmmsszzz");
}

void weight_aj::setTime(QTime t)
{
	this->time = t;
}

void weight_aj::setMass(double m, char u)
{
	this->mass.setMass(m, u);
}
