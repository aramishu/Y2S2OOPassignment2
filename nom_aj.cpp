#include "nom_aj.h"

nom_aj::nom_aj()
{
	//this->description = "";
	//this->time = QTime(0, 0, 0, 0);
	//this->energy = energy_aj(0.0f);
	this->time = QTime::currentTime();
}

nom_aj::nom_aj(QString description, QString strTime, double dwEnergy)
{
	this->description = description;
	this->time = QTime::fromString(strTime, "hhmmsszzz");
	this->energy = energy_aj(dwEnergy);
}

nom_aj::nom_aj(QString description, QString strTime, QString strEnergy)
{
	this->description = description;
	this->time = QTime::fromString(strTime, "hhmmsszzz");
	this->energy = energy_aj(strEnergy.toDouble());
}


QString nom_aj::getDescription() const
{
	return this->description;
}

void nom_aj::setDecription(QString newString)
{
	this->description = newString;
}

QTime nom_aj::getTime() const
{
	return this->time;
}

QString nom_aj::getTimeString() const
{
	return this->time.toString("hh:mm:ss");//("hh:mm:ss.zzz");
}

QString nom_aj::getTimeStr() const
{
	return this->time.toString("hhmmsszzz");
}

int nom_aj::getTimeInt() const
{
	return this->time.toString("hhmmsszzz").toInt();
}

double nom_aj::getEnergy() const
{
	return this->energy.getEnergy();
}

double nom_aj::getEnergy(char unit) const
{
	return this->energy.getEnergy(unit);
}

QString nom_aj::getEnergyStr() const
{
	return this->energy.getEnergyStr();
}

void nom_aj::setEnergy(double newValue)
{
	this->energy.setEnergy(newValue);
}

void nom_aj::setEnergy(double newValue, char unit)
{
	this->energy.setEnergy(newValue, unit);
}

void nom_aj::setTime(QTime t)
{
	this->time = t;
}
