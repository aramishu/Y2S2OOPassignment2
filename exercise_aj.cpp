#include "exercise_aj.h"

exercise_aj::exercise_aj()
{
	this->completed = false;
	this->type = "";
	this->distance = distance_aj(0.0f);
	this->energy = energy_aj(0.0f);
	this->note = "";
}

exercise_aj::exercise_aj(QString type)
{
	this->completed = false;
	this->type = type;
	this->distance = distance_aj(0.0f);
	this->energy = energy_aj(0.0f);
	this->note = "";
}

exercise_aj::exercise_aj(bool completed, QString type, double dwDistance, double dwEnergy, QString note)
{
	this->completed = completed;
	this->type = type;
	this->distance = distance_aj(dwDistance);
	this->energy = energy_aj(dwEnergy);
	this->note = note;
}


exercise_aj::exercise_aj(bool completed, QString type, QString strDistance, QString strEnergy, QString note)
{
	this->completed = completed;
	this->type = type;
	this->distance = distance_aj(strDistance.toDouble());
	this->energy = energy_aj(strEnergy.toDouble());
	this->note = note;
}

exercise_aj::exercise_aj(QString completed, QString type, QString strDistance, QString strEnergy, QString note)
{
	this->completed = (completed.toInt() == 1) ? true : false;
	this->type = type;
	this->distance = distance_aj(strDistance.toDouble());
	this->energy = energy_aj(strEnergy.toDouble());
	this->note = note;
}

QString exercise_aj::getType() const
{
	return this->type;
}

bool exercise_aj::getCompletion() const
{
	return this->completed;
}

void exercise_aj::setCompletion(bool completion)
{
	this->completed = completion;
}

void exercise_aj::setType(QString newValue)
{
	this->type = newValue;
}

double exercise_aj::getDistance() const
{
	return this->distance.getDistance();
}

double exercise_aj::getDistance(char unit) const
{
	return this->distance.getDistance(unit);
}

void exercise_aj::setDistance(double newValue)
{
	this->distance.setDistance(newValue);
}

void exercise_aj::setDistance(double newValue, char unit)
{
	this->distance.setDistance(newValue, unit);
}

double exercise_aj::getEnergy() const
{
	return this->energy.getEnergy();
}

double exercise_aj::getEnergy(char unit) const
{
	return this->energy.getEnergy(unit);
}

void exercise_aj::setEnergy(double newValue)
{
	this->energy.setEnergy(newValue);
}

void exercise_aj::setEnergy(double newValue, char unit)
{
	this->energy.setEnergy(newValue, unit);
}

QString exercise_aj::getNote() const
{
	return this->note;
}

void exercise_aj::setNote(QString newValue)
{
	this->note = newValue;
}
